#pragma once
class Sum
{
public:
	int value, x, y;
	Sum(void);
	Sum(int value);
	Sum(int value, int x, int y);
	bool operator < (const Sum &comp) const;
	~Sum(void);
};

