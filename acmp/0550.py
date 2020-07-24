#   Автор кода: Вадим Зинов (zv.proger@yandex.ru)
#   Решение задачи 0550 с сайта acmp.ru

from datetime import date as dt, timedelta as td
print((dt(int(input()), 1, 1) + td(days=255)).strftime("%d/%m/%Y"))