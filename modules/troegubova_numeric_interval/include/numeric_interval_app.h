// Copyright 2022 Petrova Polina

#ifndef MODULES_TROEGUBOVA_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_APP_H_
#define MODULES_TROEGUBOVA_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_APP_H_

#include <string>
#include <vector>

class Application {
public:
	Application();
	std::string operator()(int argc, const char** argv);

private:
	void help(const char* appname, const char* message = "");
	bool validateNumberOfArguments(int argc, const char** argv);
	std::string message_;
	typedef struct {
		int left_border;
		int right_border;
		bool left_include;
		bool right_include;
		std::vector<int> range;
	} Arguments;
};

#endif // MODULES_TROEGUBOVA_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_APP_H_
