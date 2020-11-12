import pystan as stan
import numpy as np
#import matplotlib.pyplot as plt
import datetime
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.utils import resample
from scipy.stats import bernoulli
import scipy
import itertools
import arviz as az
import sys

SEED = 12345

df = pd.read_csv(sys.argv[1])
df['offer'] = df['offer'].str.replace('$', '')
df['offer'] = df['offer'].astype(float)
df['accept'] = df['accept'].astype(int)

stan_model = '''
data {
    int<lower=0> N;
    vector[N] x;
    int<lower=0,upper=1> y[N];
}
parameters {
    real alpha;   // intercept
    real beta;    // coefficients
}
model {
        y ~ bernoulli_logit(alpha + beta * x);   // likelihood
}
generated quantities {
    real x_crit = (logit(0.5) - alpha) / beta;
}
'''

sm = stan.StanModel(model_code=stan_model, model_name='my_model')

data = dict(N = len(df),
            x = df.offer.values,
            y = df.accept.values )
            

fit = sm.sampling(data=data, chains=4, iter=1000, warmup=1000)


print(fit)

