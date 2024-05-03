#include "iostream"
#include "fstream"
using namespace std;

const int MAX = 20;

struct maTrix {
	int maTranKe[MAX][MAX];
	int soDinh;
};

void readFile(maTrix& mtk) {
	ifstream inFile("Text.txt");
	if (!inFile.is_open()) {
		cout << "\nKhong the mo tep";
		return;
	}

	inFile >> mtk.soDinh;
	for (int i = 0; i < mtk.soDinh; i++) {
		for (int j = 0; j < mtk.soDinh; j++) {
			inFile >> mtk.maTranKe[i][j];
		}
	}
	inFile.close();
}

void outputMaTrix(maTrix mtk) {
	cout << "\nMA TRAN KE: " << endl;
	for (int i = 0; i < mtk.soDinh; i++) {
		for (int j = 0; j < mtk.soDinh; j++) {
			cout << mtk.maTranKe[i][j] << "\t";
		}
		cout << endl;
	}
}

//  Hàm trả về số cạnh của đồ thị
int soCanhDoThi(maTrix mtk) {
	int tongSoCanh = 0;
	for (int i = 0; i < mtk.soDinh; i++) {
		for (int j = 0; j < mtk.soDinh; j++) {
			if (mtk.maTranKe[i][j] != 0)
				tongSoCanh++;
		}
	}
	return tongSoCanh;
}

// Tính bậc ra của đồ thị 
int outDeg(maTrix mtk, int dinhU) {
	int soBacRa = 0;
	for (int i = 0; i < mtk.soDinh; i++) {
		if (mtk.maTranKe[dinhU][i] != 0)
			soBacRa++;
	}
	return soBacRa;
}

// Cho đỉnh u, tìm đỉnh v sao cho cạnh (u,v) có trọng số lớn nhất 
bool canhLonNhat(maTrix mtk, int dinhU, int& dinhV) {
	for (int i = 0; i < mtk.soDinh; i++) {
		if (mtk.maTranKe[dinhU][i] > mtk.maTranKe[dinhU][dinhV])
			dinhV = i;
	}
	return true;
}

int main() {
	maTrix mtk;
	readFile(mtk);
	outputMaTrix(mtk);

	return 0;
}