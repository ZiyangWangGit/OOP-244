/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP244
*

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#ifndef SDD_LABEL_H
#define SDD_LABEL_H

using namespace std;
namespace sdds {
	const int contentSize = 71;
	const int frameSize = 9;

	class Label {
	private:
		char* frame;
		char* labelContent;

		void frameInfo(const char* frame);
		void contentInfo(const char* content);

	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();

		istream& readLabel();
		std::ostream& printLabel()const;
		Label& text(const char* content);
	};
}
#endif
