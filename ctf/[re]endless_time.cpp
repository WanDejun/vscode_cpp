#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define i32 long


int main()
{
  unsigned int v0; // eax
  char v10[43]; // [rsp+20h] [rbp-60h]
  char v9[43]; // [rsp+50h] [rbp-30h] BYREF
  char v2[10] = "DASCTF";
  int i; // [rsp+7Ch] [rbp-4h]
  bool flag;

  *(i64 *)v9 = 0xCE41C6BAB87CD5FA;
  *(i64 *)&v9[8] = 0xBEB4594FEBDDA9A;
  *(i64 *)&v9[16] = 0x51749DEE9D6F0A18;
  *(i64 *)&v9[24] = 0x4CD4AC84788767F;
  *(i64 *)&v9[32] = 0xA41B74A86D72631A;
  *(i32 *)&v9[39] = 10870948;
  //v0 = time(0ll);
  for (i64 j = 0; j < UINTMAX_MAX; j++) {
    srand(j);
    v10[42] = 0;
    flag = 1;
    for ( i = 0; i <= 41; ++i )
        v10[i] = rand() ^ v9[i];
    for (i64 k = 0; k <= 5 && flag; k++) {
        if (v10[k] != v2[k]) flag = 0;
    }
    if (flag) {
        for (i64 k = 0; k <= 41; k++) {putchar(v10[k]);}
    }
  }
  puts("\nsave your time boi (flag starts with DASCTF)");
  printf("this time, you get:%s", v9);

  system("pause");
  return 0;
}