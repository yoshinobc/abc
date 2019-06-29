import re
import sys

file_name = sys.argv[1] #入力ファイル名
N = sys.argv[2] #出力件数
f = open(file_name,encoding="utf-16")
text = f.read()
content = re.split("[ .,/\n]",text) #textを分割したリスト
word_dict = {} #単語をカウントしておくための辞書
for c in content:
    if c == "マルチバイト文字":
        continue
    if c in word_dict.keys():
        word_dict[c] += 1
    else:
        word_dict[c] = 1
word_dict.pop("")
sorted_dict = sorted(word_dict.items(),key=lambda x:x[1],reverse=True) #辞書のvalueでソート
for i in range(int(N)):
    print(sorted_dict[i][0],": ",sorted_dict[i][1])
