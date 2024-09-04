#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int binary(int num_10);
int reverse(int num);
int octal(int num_10);

int main(void)
{
  // int n_10;
  // int n_2 = binary(n_10);
  // int n_8 = octal(n_10);
  int pal = 10;
  int rev_10, pal_2, pal_8, rev_2, rev_8;

  while (1)
  {
    rev_10 = reverse(pal);
    pal_2 = binary(pal);
    pal_8 = octal(pal);
    rev_2 = reverse(pal_2);
    rev_8 = reverse(pal_8);
    if ((pal == rev_10) && (pal_2 == rev_2) && (pal_8 == rev_8))
    {
      printf("%d\n", pal);
      break;
    }
    pal++;
  }
  return 0;
}

int reverse(int num)
{
  int reverse = 0;
  while (num > 0)
  {
    reverse = reverse * 10 + num % 10; // reverseに入っていた値と上の桁に持っていき、numの1桁目と足す。
    num /= 10;                         // numを下にずらしていく。
  }
  return reverse;
}

// 2進数に変換して整数を返す関数
int binary(int num_10)
{
  int num_2 = 0;
  int place = 1; // 2進数の桁を管理する変数

  while (num_10 > 0)
  {
    num_2 += (num_10 % 2) * place; // 2進数の各ビットを計算
    num_10 /= 2;
    place *= 10; // 次の桁に進む
  }

  return num_2;
}

int octal(int num_10)
{
  int num_8 = 0;
  int place = 1; // 8進数の桁を管理する変数

  while (num_10 > 0)
  {
    num_8 += (num_10 % 8) * place; // 8進数の各ビットを計算
    num_10 /= 8;
    place *= 10; // 次の桁に進む
  }

  return num_8;
}