# You can call any fucntion with dataframe and column to get,drop or limit outlier
# just added the functions for the specific working on any suiting dataframe you can read and pass 

import pandas as pd
import numpy as np

# change the file name here
data_file="mydata.csv"
df=pd.read_csv(data_file)

def get_outliers(df,col):
  q1= df[col].quantile(0.25)
  q3= df[col].quantile(0.75)
  iqr= q3-q1
  #print(iqr)
  lower_lim= q1 - 1.5*iqr
  upper_lim= q3 + 1.5*iqr

  outliers= df[((df[col]<lower_lim) | (df[col]>upper_lim)).any(axis=1)]
  return(outliers)


def drop_outliers(df,col):
  q1= df[col].quantile(0.25)
  q3= df[col].quantile(0.75)
  iqr= q3-q1
  #print(iqr)
  lower_lim= q1 - 1.5*iqr
  upper_lim= q3 + 1.5*iqr

  newdf= df[~((df[col]<lower_lim) | (df[col]>upper_lim)).any(axis=1)]
  return newdf

def limit_outliers(df,col):
  q1= df[col].quantile(0.25)
  q3= df[col].quantile(0.75)
  iqr= q3-q1
  #print(iqr)
  
  #use this or below method
  lower_lim_iqr= q1 - 1.5*iqr
  upper_lim_iqr= q3 + 1.5*iqr

  #print(lower_lim_iqr)
  #print(upper_lim_iqr)

  lower_lim= df[col].quantile(0.05)
  upper_lim= df[col].quantile(0.95)

  clip_df=df.copy()
  #print(lower_lim)
  #print(upper_lim)
  clip_df[col]=clip_df[col].clip(lower_lim_iqr,upper_lim_iqr,axis=1)
  return clip_df
