#scrapes all leetcode problems from downloaded input html file (readme_generation.html)

from bs4 import BeautifulSoup
import csv

to_write=[]
soup = BeautifulSoup(open("readme_generation.html", encoding="utf8"), "html.parser")
table = soup.find('tbody', class_='reactable-data') 
rows = table.findChildren(['tr'])
iter = 0

for row in rows:
    problem = {}
    cells = row.findChildren('td')
    for cell in cells:
        value = cell.string
        if(value is None) :
            value = cell.get('value')
        problem[iter] = value
        iter = iter + 1
    iter = 0
    to_write.append(problem)

filename = 'readme_generation.csv'
with open(filename, 'w', newline='') as f:
    w = csv.DictWriter(f,[0,1,2,3,4,5,6])
    w.writeheader()
    for row in to_write:
        w.writerow(row)

#convert the csv file into markdown table format

import pandas as pd
import emoji

df = pd.read_csv('readme_generation.csv', encoding= 'ISO-8859-1', low_memory=False)

df = df.iloc[1: , :]
df = df.iloc[: , 1:]

df['combined'] = df[['1', '2']].apply(lambda row: '. '.join(row.values.astype(str)), axis=1)

for col in df:
    df['combined'] = df['combined'].str[:24]

for index, row in df.iterrows():
    diffval = 0
    if(row['5'] == 'Hard'):
        diffval = emoji.emojize(':red_circle:')
    elif(row['5'] == 'Medium'):
        diffval = emoji.emojize(':yellow_circle:')
    elif(row['5'] == 'Easy'):
        diffval = emoji.emojize(':green_circle:')
    print(f"|{diffval}|[{row['combined']}]()||||||")