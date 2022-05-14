#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  char *p = argv[1];

  printf(".intel_syntax noprefix\n");
  printf(".globl main\n");
  printf("main:\n");
  printf("  mov rax, %ld\n", strtol(p, &p, 10));

  while (*p)
  {
    // printf("\n The ASCII value of the character is : %c\n", *p);
    // printf("(%s)\n", p);
    // アドレスは ASCII(0x7fff3f08b922)に定義されている
    // %d(整数にキャストされる), %p, &(*p)(ポインタ(ASCII)にキャストされる), %c (char型にキャストされる)
    // ASCII => charに変換可能, ASCII => 10進数に変換可能
    if (*p == '+')
    {
      p++;
      printf("  add rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    if (*p == '-')
    {
      p++;
      printf("  sub rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    fprintf(stderr, "予期しない文字です: '%c'\n", *p);
    return 1;
  }

  printf("  ret\n");
  return 0;
}