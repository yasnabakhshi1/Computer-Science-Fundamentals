from cs50 import get_string

text = get_string("text: ")

letters = 0
for char in text:
    if char.isalpha():
        letters += 1

words = len(text.split())

sentences = 0
for char in text:
    if char in ['.', '?', '!']:
        sentences += 1

if words == 0:
    L = 0
    S = 0
else:
    L = (letters / words) * 100
    S = (sentences / words) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
