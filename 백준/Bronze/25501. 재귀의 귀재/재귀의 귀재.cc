#include <stdio.h>
#include <string.h>

int c = 0;;

int recursion(const char* s, int l, int r) {
    c++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    printf("%d ", recursion(s, 0, strlen(s) - 1));

    int res = c;
    c = 0;
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        c = 0;
        char cT[1001];
        scanf("%s", &cT);
        printf("%d\n", isPalindrome(cT));
    }

    return 0;
}