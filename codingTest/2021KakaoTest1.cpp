#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

//1단계 대문자 'B'와 'T'가 소문자 'b'와 't'로 바뀌었습니다.
//"...!@BaT#*..y.abcdefghijklm" → "...!@bat#*..y.abcdefghijklm"
//
//2단계 '!', '@', '#', '*' 문자가 제거되었습니다.
//"...!@bat#*..y.abcdefghijklm" → "...bat..y.abcdefghijklm"
//
//3단계 '...'와 '..' 가 '.'로 바뀌었습니다.
//"...bat..y.abcdefghijklm" → ".bat.y.abcdefghijklm"

string solution(string new_id) {
	string answer = new_id;
	char character[] = "`!@#$%^&*()=/"; // 정규표현식으로 바꾸기?

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