#include "TTasks.h"

std::vector<TTasks::oneTask>TTasks::getTasks() {
	int countStruct = 0; // ������� ��������
	std::vector<std::string>tmpVectString;
	// ������ ��� ���������� �������� ����������� ������
	std::vector<oneTask>vec_singlTask; // ������� ������ ��������
	oneTask str_singlTask; // ������� ������ ���������
	std::fstream finTasks; // ����� ������ �������
	std::string lineTaskBuf;
	// ������� �����, ���� ����� ����������� ������ �� �����
	finTasks.open("tasks.tsk", std::ios::in); // ��������� ���� ��� ������
	if (finTasks) // ���� ���� ��������
	{
		while (getline(finTasks, lineTaskBuf)) {

			tmpVectString = this->split(lineTaskBuf);
			// �������� ������ �� ���������� � ������
			vec_singlTask.push_back(str_singlTask);
			// �������� ���� ��������� � ������

			strcpy(vec_singlTask.at(countStruct).inPath,
				tmpVectString[0].c_str());
			strcpy(vec_singlTask.at(countStruct).outPath,
				tmpVectString[1].c_str());
			vec_singlTask.at(countStruct).lid =
				std::atoi(tmpVectString[2].c_str());

			countStruct++;

		}
		finTasks.close();
	}
	return vec_singlTask;
}

void TTasks::addTask(std::string task) {
	std::fstream foutTask; // ����� ������ �������
	foutTask.open("tasks.tsk", std::ios::out | std::ios::app);
	foutTask << task;
	foutTask.close();
}

bool TTasks::deleteTask(size_t numberTask) {
	std::vector<std::string>vec;
	std::ifstream file("tasks.tsk");
	if (file.is_open()) {
		std::string str;
		while (std::getline(file, str))
			vec.push_back(str);
		file.close();
		if (vec.size() < numberTask)
			return false;
		vec.erase(vec.begin() + numberTask);
		std::ofstream outfile("tasks.tsk");
		if (outfile.is_open()) {
			std::copy(vec.begin(), vec.end(),
				std::ostream_iterator<std::string>(outfile, "\n"));
			outfile.close();
			return true;
		}
		return false;
	}
	return false;

}

std::vector<std::string>TTasks::split(std::string &strToSplit) {
	std::vector<std::string>result;
	char separator = ';';

	std::string::size_type start = 0;
	std::string::size_type end;
	while ((end = strToSplit.find(separator, start)) != std::string::npos) {
		if (start != end)
			result.push_back(strToSplit.substr(start, end - start));
		start = end + 1;
	}
	if (start != strToSplit.size())
		result.push_back(strToSplit.substr(start));
	return result;

}
