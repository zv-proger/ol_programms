#   ����� ����: ����� ����� (zv.proger@yandex.ru)
#   ������� ������ 0550 � ����� acmp.ru

from datetime import date as dt, timedelta as td
print((dt(int(input()), 1, 1) + td(days=255)).strftime("%d/%m/%Y"))