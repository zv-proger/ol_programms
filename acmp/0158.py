#   ����� ����: ����� ����� (zv.proger@yandex.ru)
#   ������� ������ 0401 � ����� acmp.ru
   

from math import factorial as f

x, a = map(int, input().split())
x //= 5

print(f(a + x) // f(a) // f(x));