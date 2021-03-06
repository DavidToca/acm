#include <stdio.h>

#define MAXS 1024
#define INF 0x1FFFFFFF

int h, k;

int sol_a[16], sol_n;
int a[16];

void find(int s[], int p)
{
	int t[MAXS];
	int i, j, m;

	if (p >= k) {
		printf("{"); for(i=0;i<k;i++)printf(" %d",a[i]);
		printf(" }: ");
		for (i = 0; s[i] < INF; i++) printf("%2d", s[i]);
		printf("\n");

		i--;
		if (i > sol_n) {
			sol_n = i;
			memcpy(sol_a, a, sizeof(a));
		}

		return;
	}

	for (a[p] = a[p - 1] + 1; s[a[p] - 1] < INF; a[p]++) {
		for (i = 0; i < MAXS; i++) {
			t[i] = s[i];

			for (j = 1; j <= h && (i - a[p] * j) >= 0; j++) {
				m = s[i - j * a[p]] + j;

				if (m < t[i] && m <= h)
					t[i] = m;
			}
		}

		find(t, p + 1);
	}
}

int main()
{
	int s[MAXS], i;

	while (scanf("%d %d", &h, &k) == 2) {
		a[0] = 1;

		for (i = 0; i < MAXS; i++)
			s[i] = INF;

		s[0] = 0;

		for (i = 1; i <= h; i++)
			s[i] = i;

		sol_n = -1;

		find(s, 1);

		for (i = 0; i < k; i++)
			printf("%3d", sol_a[i]);
		printf(" ->%3d\n", sol_n);
	}

	return 0;
}
