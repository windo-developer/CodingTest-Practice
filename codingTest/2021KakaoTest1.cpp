#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

//1�ܰ� �빮�� 'B'�� 'T'�� �ҹ��� 'b'�� 't'�� �ٲ�����ϴ�.
//"...!@BaT#*..y.abcdefghijklm" �� "...!@bat#*..y.abcdefghijklm"
//
//2�ܰ� '!', '@', '#', '*' ���ڰ� ���ŵǾ����ϴ�.
//"...!@bat#*..y.abcdefghijklm" �� "...bat..y.abcdefghijklm"
//
//3�ܰ� '...'�� '..' �� '.'�� �ٲ�����ϴ�.
//"...bat..y.abcdefghijklm" �� ".bat.y.abcdefghijklm"

string solution(string new_id) {
	string answer = new_id;
	char character[] = "`!@#$%^&*()=/"; // ����ǥ�������� �ٲٱ�?

	transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

	for (int i = 0; i < sizeof(character); i++)
	{
		answer.erase(remove(answer.begin(), answer.end(), character[i]));
	}
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	return answer;
}

int main()
{
	cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;

	return 0;
}