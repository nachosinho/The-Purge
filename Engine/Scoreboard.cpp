#include "Scoreboard.h"

Score::Score(string _name, int _score)
	: m_Name(_name), m_Score(_score) {}

ScoreBoard::ScoreBoard(void) {
	this->m_ScoreVec = new vector<Score>;

	this->loadScoreBoard();
}

void ScoreBoard::loadScoreBoard(void) {
	if (this->m_ScoreVec == nullptr)
		return;

	ifstream input("scoreboard.txt");
	if (!input.is_open())
		return;
	string line;
	while (getline(input, line)) {
		string key;
		int value;
		char comma;
		stringstream lineStream(line);
		if (getline(lineStream, key, ',') &&
			lineStream >> value &&
			lineStream >> comma)
			this->m_ScoreVec->push_back(Score(key, value));
	}

	if (this->m_ScoreVec->size() > 5)
		this->m_ScoreVec->resize(5);

	input.close();

}

void ScoreBoard::saveScoreBoard(void) {
	if (this->m_ScoreVec == nullptr)
		return;

	ofstream output("scoreboard.txt");
	if (output.is_open()) {

		for (Score _score : *this->m_ScoreVec)
			output << _score.m_Name << "," << _score.m_Score << endl;

		std::cout << "x" << " " << "d" << endl;
		output.close();
	}
}
bool sortByScore(const Score& _a, const Score& _b) {
	return _a.m_Score < _b.m_Score;
}
void ScoreBoard::addScore(int _score) {
	if (this->m_ScoreVec == nullptr)
		return;

	string name = getenv("USERNAME");

	this->m_ScoreVec->push_back(Score(name, _score));
	sort(this->m_ScoreVec->begin(), this->m_ScoreVec->end(), sortByScore);
	if (this->m_ScoreVec->size() > 5)
		this->m_ScoreVec->resize(5);
}

