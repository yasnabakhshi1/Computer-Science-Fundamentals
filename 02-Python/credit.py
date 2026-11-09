from cs50 import get_string

while True:
    cardnum = get_string("number: ")
    if cardnum.isdigit():
        break

evens = 0
odds = 0

card = reversed([int(digit) for digit in cardnum])

for i, digit in enumerate(card):
    if (i + 1) % 2 == 0:
        digit_doubled = digit * 2
        evens += (digit_doubled // 10) + (digit_doubled % 10)
    else:
        odds += digit

sum_total = evens + odds

if sum_total % 10 == 0:
    clen = len(cardnum)
    start_two = int(cardnum[0:2])
    start_one = int(cardnum[0])

    if clen == 15 and start_two in [34, 37]:
        print("AMEX")
    elif clen == 16 and start_two in range(51, 56):
        print("MASTERCARD")
    elif (clen == 13 or clen == 16) and start_one == 4:
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
