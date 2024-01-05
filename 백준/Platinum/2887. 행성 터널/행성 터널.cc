#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct planet {
	int num, x, y, z;
};

vector<planet> vertex;
vector<pair<int, pair<int, int>>> edge; // cost, ( v1, v2 )

bool compareX(planet a, planet b) {
	return a.x < b.x;
}

bool compareY(planet a, planet b) {
	return a.y < b.y;
}

bool compareZ(planet a, planet b) {
	return a.z < b.z;
}

int parent[100001];

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	parent[b] = a;
}



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	// 부모 배열 초기화
	for (int i = 1; i < N; i++) {
		parent[i] = i;
	}

	// 행성 정보 입력받기
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		vertex.push_back({ i,x,y,z });
	}
	
	// 1. 간선 비용 구하기
	// x, y, z축 기준으로 정렬 -> 인접 인덱스끼리 계산 (각 노드마다 간선 6개)
	sort(vertex.begin(), vertex.end(), compareX);
	
	for (int i = 0; i < N - 1; i++) {
		planet p1 = vertex[i];
		planet p2 = vertex[i + 1];
		int w = p2.x - p1.x;

		//if (w == 0) continue;
		edge.push_back(make_pair(w, make_pair(p1.num, p2.num)));
	}

	// y
	sort(vertex.begin(), vertex.end(), compareY);
	
	for (int i = 0; i < N - 1; i++) {
		planet p1 = vertex[i];
		planet p2 = vertex[i + 1];
		int w = p2.y - p1.y;

		//if (w == 0) continue;
		edge.push_back(make_pair(w, make_pair(p1.num, p2.num)));
	}

	// z
	sort(vertex.begin(), vertex.end(), compareZ);
	
	for (int i = 0; i < N - 1; i++) {
		planet p1 = vertex[i];
		planet p2 = vertex[i + 1];
		int w = p2.z - p1.z;

		//if (w == 0) continue;
		edge.push_back(make_pair(w, make_pair(p1.num, p2.num)));
	}

	// 2. 크루스칼
	int ans = 0;
	// (1) cost 순으로 vector를 정렬
	sort(edge.begin(), edge.end());

	// (2) 각각 find(v1), find(v2)
	for (int i = 0; i < edge.size(); i++) {
		int cost = edge[i].first;
		int v1 = edge[i].second.first;
		int v2 = edge[i].second.second;

		// (3) 두 점의 부모가 다르면, ans에 cost 더하고 union
		if (find(v1) != find(v2)) {
			ans += cost;
			uni(v1, v2);
		}
	}
	
	cout << ans;

	return 0;
}