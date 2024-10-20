typedef struct {

	int x;

	int y;

} Pos;

inline int Max(int a, Pos pos) {

	int b = pos.x * pos.x + pos.y * pos.y;

	return a > b ? a : b;

}

#define MAX_OBS_LEN 10010

int h[60010];

int idx;

int e[MAX_OBS_LEN];

int ne[MAX_OBS_LEN];

bool Check(int x, int y) {

// printf("x, y = (%d, %d)\n", x, y);

	for (int i = h[x]; i != -1; i = ne[i]) {

		int j = e[i];

// printf("%d, %d\n", x, j);

		if (j == y) {

			return true;

		}

	}

	return false;

}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {

	memset(h, -1, sizeof(h));

	idx = 0;

	int base = 30000;

	for (int i = 0; i < obstaclesSize; i++) {

		int x = obstacles[i][0] + base;

		int y = obstacles[i][1];

		e[++idx] = y;                       //e[1]=3  ne[1]=-1  h[x]=1         
		                                    //e[2]=4  ne[2]=1   h[x]=2

		ne[idx] = h[x];

		h[x] = idx;

	}

	int dx[4] = {0, -1, 0, 1};

	int dy[4] = {1, 0, -1, 0};

	int direct = 0;

	Pos cur = {0, 0};

	int ans = 0;

	for (int i = 0; i < commandsSize; i++) {

		int c = commands[i];

		if (c == -2) {

			direct = (direct + 1) % 4;

		} else if (c == -1) {

			direct = (direct + 3) % 4;

		} else {

			for (int j = 0; j < c; j++) {

				int nx = cur.x + dx[direct];

				int ny = cur.y + dy[direct];

				if (!Check(nx + base, ny)) {

					cur.x = nx;

					cur.y = ny;

				}

			}

			ans = Max(ans, cur);

		}

	}

	return ans;

}
