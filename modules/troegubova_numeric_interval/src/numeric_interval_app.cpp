// Copyright 2022 Petrova Polina


#include "include/numeric_interval.h"
#include "include/numeric_interval_app.h"

#include <iostream>
#include <vector>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sstream>

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
	message_ =
		std::string(message) +
		"This is application works with numeric intervals. \n\n" +
		"Determines whether the given range is contained in the interval\n\n" +
		"Please provide arguments in the following format: \n\n" +

		" $ " + appname + " <left border> <right border>" +
		"<include left border> <include right border> <your range>\n\n" +

		"Where left and right borders are int-precision numbers" +
		"and <include left border> and <include right border>" +
		"have value true or false.\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
	if (argc == 1) {
		help(argv[0]);
		return false;
	} else if (argc != 6) {
		help(argv[0], "ERROR: Should be 5 arguments. \n\n");
		return false;
	}
	return false;
}
int parseInt(const char* arg) {
	char* end;
	int value = static_cast<int>(strtod(arg,&end));

	if (end[0]) {
		throw std::string("Wrong numder format!");
	}
	return value;
}
bool parserBool(const char* arg) {
	bool f;
	if (strcmp(arg, "true") == 0) {
		f = true;
	} else if (strcmp(arg, "false") == 0) {
		f = false;
	} else {
		throw std::string("Wrong value!");
	}
	return f;
}
std::vector<int> parserVector(const char* arg) {
	char* end;
	int n;
	std::string strVec = arg;
	std::string strInt = "";
	std::vector<int> vec;

	for (unsigned int i = 0; i < strVec.size(); i++) {
		if (strVec[i] == ',') {
			if (strInt == "") {
				throw std::string("Wrong vector format!");
			}
			n = static_cast<int>(strtod(strInt.c_str(), &end));
			if (end[0]) {
				throw std::string("Wrong vector format!");
			}
			vec.push_back(n);
			strInt = "";
		} else {
			strInt += strVec[i];
		}
		if (strInt == "") {
			throw std::string("Wrong vector format!");
		}
		n = static_cast<int>(strtod(strInt.c_str(), &end));
		if (end[0])
			throw std::string("Wrong vector format!");
	}
	vec.push_back(n);

	return vec;
}

std::string Application::operator() (int argc, const char** argv) {
	Arguments args;
	std::ostringstream stream;

	if (!validateNumberOfArguments(argc, argv)) {
		return message_;
	}
	try {
		args.left_border = parseInt(argv[1]);
		args.right_border = parseInt(argv[2]);
		args.left_include = parserBool(argv[3]);
		args.right_include = parserBool(argv[4]);
		args.range = parserVector(argv[5]);
	} catch (std::string& str) {
		return str;
	}
	NamericInterval interval(args.left_border, args.right_border, args.left_include, args.right_include);
	std::string brack_l, brack_r;
	if (args.left_include == true) {
		brack_l = "[";
	} else {
		brack_l = "(";
	}
    if (args.right_include == true) {
		brack_r = "]";
    } else {
        brack_r = ")";
    }

    stream << "your interval: " << brack_l << args.left_border << " , "
        << args.right_border << brack_r << std::endl;
    stream << "your range: ";
	for (unsigned int i = 0; i < args.range.size(); i++) {
		stream << args.range[i] << " ";
    }
	try {
		bool f;
		f = interval.containsIntegerRange(args.range);
		stream << "anser: " << f;
		break;
	}
	catch (std::string& str) {
		return str;
	}
	message_ = stream.str();

	return message_;
}