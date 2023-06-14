#pragma once
#include "include.h"

struct Score {
	Score(void) {};
	Score(string, int);

	string m_Name = "UNNAMED";
	int m_Score = -1;
};

class ScoreBoard {
private:
	vector<Score>* m_ScoreVec;

	//bool sortByScore(const Score&, const Score&);
public:
	ScoreBoard();

	vector<Score>* getScore(void) { return this->m_ScoreVec; }

	void loadScoreBoard(void);
	void saveScoreBoard(void);
	void addScore(int);

};