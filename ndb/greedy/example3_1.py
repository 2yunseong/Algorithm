money = int(input())
coinCount = 0

while money != 0:
    if money >= 500:
        coinCount = coinCount + 1
        money = money - 500
        continue
    if money >= 100:
        coinCount = coinCount + 1
        money = money - 100
        continue
    if money >= 50:
        coinCount = coinCount + 1
        money = money - 50
        continue
    if money >= 10:
        coinCount = coinCount + 1
        money = money - 10

print(coinCount)
