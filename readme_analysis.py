import pandas as pd
import emoji
import codecs
import requests

r = requests.get('https://raw.githubusercontent.com/Liam-Weitzel/LeetCode/main/README.md', stream=True)
#print(r.text)

data = {'dif':[],
        'problem':[],
        'attempt1_date':[],
        'attempt1_status':[],
        'attempt2_date':[],
        'attempt2_status':[],
        'attempt3_date':[],
        'attempt3_status':[],
        'attempt4_date':[],
        'attempt4_status':[],
        'attempt5_date':[],
        'attempt5_status':[]}

def appendAttempt(attempt, attempt_date, attempt_status):
    if(attempt != ''):
        if(emoji.emojize(':green_circle:') in attempt or '🟢' in attempt):
            data[attempt_status].append('0')
        elif(emoji.emojize(':yellow_circle:') in attempt or '🟡' in attempt):
            data[attempt_status].append('1')
        elif(emoji.emojize(':orange_Circle:') in attempt or '🟠' in attempt):
            data[attempt_status].append('2')
        elif(emoji.emojize(':red_circle:') in attempt or '🔴' in attempt):
            data[attempt_status].append('3')
        data[attempt_date].append(attempt[2:])
    else:
        data[attempt_date].append(None)
        data[attempt_status].append(None)

problemSection=False
for line in r.iter_lines():
    if(line):
        line = line.decode('utf-8')
        if(problemSection):
            [startline, dif, problem, attempt1, attempt2, attempt3, attempt4, attempt5, endline]=line.split("|")
            #print(f"{dif}, {problem}, {attempt1}, {attempt2}, {attempt3}, {attempt4}, {attempt5}")
            if(dif == emoji.emojize(':green_circle:')):
                data['dif'].append('easy')
            elif(dif == emoji.emojize(':yellow_circle:')):
                data['dif'].append('medium')
            elif(dif == emoji.emojize(':red_circle:')):
                data['dif'].append('hard')
            data['problem'].append(problem)

            appendAttempt(attempt1, 'attempt1_date', 'attempt1_status')
            appendAttempt(attempt2, 'attempt2_date', 'attempt2_status')
            appendAttempt(attempt3, 'attempt3_date', 'attempt3_status')
            appendAttempt(attempt4, 'attempt4_date', 'attempt4_status')
            appendAttempt(attempt5, 'attempt5_date', 'attempt5_status')

        if("|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|" in line):
            problemSection = True

df = pd.DataFrame(data)
df['attempt1_date'] = pd.to_datetime(df['attempt1_date'], format='%b %d, %Y')
df['attempt2_date'] = pd.to_datetime(df['attempt2_date'], format='%b %d, %Y')
df['attempt3_date'] = pd.to_datetime(df['attempt3_date'], format='%b %d, %Y')
df['attempt4_date'] = pd.to_datetime(df['attempt4_date'], format='%b %d, %Y')
df['attempt5_date'] = pd.to_datetime(df['attempt5_date'], format='%b %d, %Y')

print(df)