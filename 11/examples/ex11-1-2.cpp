#include <iostream>
#include <cstring>
using namespace std;

// 각 클래스에 (깊은)복사 생성자와 대입 연산자 정의

class Book {
private:
	char *title;
	char *isbn;
	int price;
public:
	Book(const char *title, const char *isbn, int price)
		: price(price) {
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);
	}
	Book(const Book &ref) : price(ref.price) { // 깊은 복사 생성자
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
	}
	Book &operator=(const Book &ref) { // 대입 연산자.
		delete[]title;
		delete[]isbn;

		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
		price = ref.price;

		return *this;
	}
	~Book() {
		delete[]title;
		delete[]isbn;
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class EBook : public Book {
private:
	char *DRMKey;
public:
	EBook(const char *title, const char *isbn, int price, const char *DRMKey)
		:Book(title, isbn, price) {
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}
	EBook(const EBook &ref) :Book(ref) {
		DRMKey = new char[strlen(ref.DRMKey)];
		strcpy(DRMKey, ref.DRMKey);
	}
	EBook &operator=(const EBook &ref) {
		Book::operator=(ref);
		delete[]DRMKey;
		DRMKey = new char[strlen(ref.DRMKey)];
		strcpy(DRMKey, ref.DRMKey);

		return *this;
	}
	~EBook() {
		delete[]DRMKey;
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl << endl;
	}
};

int main(void) {
	Book book1("좋은 C++", "555-12345-890-0", 20000);
	Book book2 = book1; // 복사 생성자를 통한 객체 선언
	Book book3("일론머스크형", "111-222-333-1", 999999);
	book3 = book1;

	book1.ShowBookInfo();
	cout << endl;
	book2.ShowBookInfo();
	cout << endl;
	book3.ShowBookInfo();
	cout << endl;

	EBook ebook1("일론머스크 화성 갈끄니까", "123-123-123", 999999, "444992-111234");
	EBook ebook2 = ebook1;
	EBook ebook3("0", "0", 0, "123");
	ebook3 = ebook1;

	ebook1.ShowEBookInfo();
	ebook2.ShowEBookInfo();
	ebook3.ShowEBookInfo();
	
	return 0;
}
