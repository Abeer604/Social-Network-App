#include <iostream>
#include <string>
#include <fstream>
#include "raylib.h"
using namespace std;

class Date {
	static int day;
	static int month;
	static int year;
public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}
	//assignment operator(deep)
	Date& operator=(const Date& obj) {
		this->day = obj.day;
		this->month = obj.month;
		this->year = obj.year;
		return *this;
	}
	void setDate(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	void showDate() {
		cout << " " << day << "/" << month << "/" << year << endl;
	}
	int getDay() { return this->day; }
	int getMonth() { return this->month; }
	int getYear() { return this->year; }
	void setDay(int x) { this->day = x; }
	void setMonth(int x) { this->month = x; }
	void setYear(int x) { this->year = x; }
};
int Date::day=0;
int Date::month=0;
int Date::year=0;
class User;
class Comment {
	string text;
	User* commenter;
	int commenterId;
public:
	Comment(string , int );
	~Comment();
	/*done*/void displayComment();
	string getcomtext();
	int getcommenterId();
	void setCommenterByid(int) ;
	void setCommenter(User*& );
	void setComtext(string );
};
class Activity {
	int type;
	string value;
public:
	Activity();
	Activity(int);
	Activity(const Activity&);
	void displayActivity();
	void setActivity(int);
	void setActivitytype(int);
	void setActivityvalue(string);
	int gettype();
	string getvalue();
};
class Post;
class Page;
class User {
	int userId;
	string username;
	int friendNum;
	User** friendList;
	int noOflikedPages;
	Page** likedPages;
	Post** userposts;
	int numberOfPosts;

public:
	User();
	User(const User& obj);
	~User();
	// Getters
	string getUsername();
	int getuserId();
	int getfriendnum();
	User getuserfriend(int);
	int getnoOfpagelikes();
	Page getLikedpage(int);
	int getpostnum();
	Post* getUserposts(int);
	// Setters
	void setUserId(int);
	void setusername(string);
	void setFriendNum(int);
	void setnoOfPageLikes(int);
	void setPostNum(int);
	void createLikedPage(int);
	void createfriendlist(int);
	void setfriend(User*&, int);
	void createuserposts(int);
	void setFriendById(int);
	// Other
	void viewHome();
	void displayFriendList();
	void veiwProfile();
	void displayLikedPages(); // TODO
	void displayPosts();
};
class SocialNetworkApp {
private:
	static User* currentUser;
	static Page** allPages;
	static int pagesNum;
	static int userNumber;
public:
	static User** allUsers;
	static Date currentDate;
	//constructors
	SocialNetworkApp();
	~SocialNetworkApp();
	static User* findUserById(int );
	static User* setCurrentUser(int );
	static Post* findPostById(int );
	static Page* findPageById(int );
	static void loadData(ifstream& );
	static void storeData(ofstream& );
	static void Run();
};
User* SocialNetworkApp::currentUser = nullptr;
Page** SocialNetworkApp::allPages = nullptr;
int SocialNetworkApp::pagesNum = 0;
int SocialNetworkApp::userNumber = 0;
User** SocialNetworkApp::allUsers=nullptr;
Date SocialNetworkApp::currentDate=Date();
class Post {
	int postId;
	string description;
	Comment** postcomments;
	int noOfcomments;
	Activity postActivity;
	User** LikedBy;
	int noOfLikes;
	Date dateOfPost;
public:
	//constructors
	Post();
	Post(const Post& );
	~Post();
	//getters
	string getpostdes();
	Date getpostDate();
	int getnoOfLikes();
	int getnoOfComments();
	Activity getPostActivity();
	int getactivitytype();
	string getactivityvalue();
	Comment* getpostcomment(int );
	int getId();
	//setters
	void setPostDes(string );
	void setPostActivity(int );
	void setNoofLikes(int );
	void setNoOfComments(int );
	void setpostId(int );
	void createPostComments(int );
	/*done 4 */void displayPostLikers();
	/*done 6 */void veiwPostandComments();
	/*done 5 */void addComment(string , User*& );
	void shareMemory(int ) {}		//HOLD
	/*done 3 */ void addLike(User& );
	/*done part of 2 */ int getPostDay();
	/*done part of 2 */ void displayPostOnly();

};
class Page {
	int pageId;
	User* owner;
	string title;
	int postsnum;
	Post** pagePosts;
	int noOfLikes;
public:
	Page();
	Page(const Page& obj);
	~Page();
	/*done 10 */void veiwPage();
	string getPagetitle();
	int getpageId();
	User getPageowner();
	int getnoOfLikes();
	int getpostsnum();
	Post* getpagePosts(int x);
	void setpageId(int x);
	void setpageOwner(int o);
	void setpagetitle(string x);
	void setpagepostnum(int x);
	void setnoOflikes(int x);
	void createPagepostlist(int x);
	Post* createPagepost(int x);
};

	//Class User functions
User::User() {
	userId = 0;
	username = "";
	friendNum = 0;
	friendList = nullptr;
	noOflikedPages = 0;
	likedPages = nullptr;
	numberOfPosts = 0;
	userposts = nullptr;
}
User::User(const User& obj) {
	if (this != &obj) {
		if (&obj == nullptr) {
			userId = 0;
			username = "";
			friendNum = 0;
			noOflikedPages = 0;
			numberOfPosts = 0;
			friendList = nullptr;
			likedPages = nullptr;
			userposts = nullptr;
			return;
		}
		userId = obj.userId;
		username = obj.username;
		friendNum = obj.friendNum;
		noOflikedPages = obj.noOflikedPages;
		numberOfPosts = obj.numberOfPosts;

		friendList = new User * [friendNum];
		for (int i = 0; i < friendNum; i++) {
			friendList[i] = new User(*(obj.friendList[i]));
		}

		likedPages = new Page * [noOflikedPages];
		for (int i = 0; i < noOflikedPages; i++) {
			likedPages[i] = new Page(*(obj.likedPages[i]));
		}

		userposts = new Post * [numberOfPosts];
		for (int i = 0; i < numberOfPosts; i++) {
			userposts[i] = new Post(*(obj.userposts[i]));
		}
	}
}
User::~User() {
	for (int i = 0; i < friendNum; i++) delete friendList[i];
	for (int i = 0; i < numberOfPosts; i++) delete userposts[i];
	for (int i = 0; i < noOflikedPages; i++) delete likedPages[i];
	delete[] friendList;
	delete[] likedPages;
	delete[] userposts;
	friendList = nullptr;
	likedPages = nullptr;
	userposts = nullptr;
}
string User::getUsername() { return username; }
int User::getuserId() { return userId; }
int User::getfriendnum() { return this->friendNum; }
User User::getuserfriend(int x) { return *(friendList[x]); }
int User::getnoOfpagelikes() { return noOflikedPages; }
Page User::getLikedpage(int x) { return *(likedPages[x]); }
int User::getpostnum() { return numberOfPosts; }
Post* User::getUserposts(int i) { return userposts[i]; }
void User::setUserId(int x) { userId = x; }
void User::setusername(string u) { username = u; }
void User::setFriendNum(int x) { friendNum = x; }
void User::setnoOfPageLikes(int x) { noOflikedPages = x; }
void User::setPostNum(int x) { numberOfPosts = x; }
void User::createLikedPage(int x) { likedPages = new Page * [x]; }
void User::createfriendlist(int x) { friendList = new User * [x]; }
void User::setfriend(User*& u, int x) { friendList[x] = u; }
void User::createuserposts(int x) { userposts = new Post * [x]; }
void User::setFriendById(int x) {
	User** temp = new User * [friendNum + 1];
	for (int i = 0; i < friendNum; i++) {
		temp[i] = friendList[i];
	}
	temp[friendNum] = new User();
	temp[friendNum]->setUserId(x);
	for (int i = 0; i < friendNum; i++) delete friendList[i];
	delete[] friendList;
	friendList = temp;
	friendNum++;
}
void User::viewHome() {
	for (int i = 0; i < friendNum; i++) {
		User* ptr = friendList[i];
		for (int j = 0; j < numberOfPosts; j++) {
			Post* posptr = ptr->getUserposts(j);
			if (posptr->getPostDay() == SocialNetworkApp::currentDate.getDay() - 1 ||
				posptr->getPostDay() == SocialNetworkApp::currentDate.getDay()) {
			}

		}
	}
}
void User::displayFriendList() {
	for (int i = 0; i < friendNum; i++) {
		cout << "Friend " << i + 1 << ": " << friendList[i]->getUsername() << endl;
	}
}
void User::veiwProfile() {
	cout << "\nUsername: " << getUsername() << endl;
	cout << "Posts\n";
	displayPosts();
}
//on hold
void User::displayLikedPages() {
}
void User::displayPosts() {
	for (int i = 0; i < numberOfPosts; i++) {
		cout << "Post " << i + 1 << ": " << userposts[i]->getId() << endl;
	}
}
//Class Post functions
Post::Post() {
	postId = 0;
	description = "";
	postcomments = nullptr;
	postActivity=Activity();
	LikedBy = nullptr;
	noOfLikes = 0;
	noOfcomments = 0;
	dateOfPost.setDate(0, 0, 0);
}	
Post::Post(const Post& obj) {
	if (this != &obj) {
		this->postId = obj.postId;
		this->description = obj.description;
		this->postActivity = obj.postActivity;
		this->LikedBy = obj.LikedBy;		//ambiguity
		this->noOfLikes = obj.noOfLikes;
		this->dateOfPost = obj.dateOfPost;
		this->noOfcomments = obj.noOfcomments;
		this->postcomments = new Comment * [noOfcomments];
		for (int i = 0; i < noOfcomments; i++) {
			this->postcomments[i] = new Comment(*(obj.postcomments[i]));
		}
		this->LikedBy = new User * [noOfLikes];
		for (int i = 0; i < noOfLikes; i++) {
			this->LikedBy[i] = new User(*(obj.LikedBy[i]));
		}
	}
}
Post::~Post() {
	for (int i = 0; i < noOfcomments; i++) {
		delete this->postcomments[i];
	}
	for (int i = 0; i < noOfLikes; i++) {
		delete LikedBy[i];
	}
	delete[] this->postcomments;
	delete[] LikedBy;
	LikedBy = nullptr;
	postcomments = nullptr;
}
string Post::getpostdes() { return description; }
Date Post::getpostDate() { return dateOfPost; }
int Post::getnoOfLikes() { return noOfLikes; }
int Post::getnoOfComments() { return noOfcomments; }
Activity Post::getPostActivity() { return this->postActivity; }
int Post::getactivitytype() { return postActivity.gettype(); }
string Post::getactivityvalue() { return postActivity.getvalue(); }
Comment* Post::getpostcomment(int x) { return postcomments[x]; }
int Post::getId() { return postId; }
void Post::setPostDes(string d) { this->description = d; }
void Post::setPostActivity(int x) { postActivity.setActivity(x); }
void Post::setNoofLikes(int x) { noOfLikes = x; }
void Post::setNoOfComments(int x) { noOfcomments = x; }
void Post::setpostId(int x) { postId = x; }
void Post::createPostComments(int x) { this->postcomments = new Comment*[x]; }
/*done 4 */void Post::displayPostLikers() {
	for (int i = 0; i < noOfLikes; i++) {
		cout << "Liker " << i + 1 << ": ";
		LikedBy[i]->getUsername();
	}
}
/*done 6 */void Post::veiwPostandComments() {
	cout << "\nPost Id: " << this->postId << endl << "comments" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "comment " << i + 1 << ": ";
		postcomments[i]->displayComment();
	}
}
/*done 5 */void Post::addComment(string com, User*& commentor) {
	noOfcomments++;
	Comment** temp = new Comment * [noOfcomments];
	for (int i = 0; i < (noOfcomments - 1); i++) {
		temp[i] = this->postcomments[i];
	}
	temp[noOfcomments - 1] = new Comment(com,commentor->getuserId());
	for (int i = 0; i < (noOfcomments - 1); i++) {
		delete postcomments[i];
	}
	delete[] this->postcomments;
	postcomments = temp;
}
/*done 3 */ void Post::addLike(User& liker) {
	noOfLikes++;
	User** temp = new User * [noOfLikes];
	for (int i = 0; i < (noOfLikes - 1); i++) {
		temp[i] = LikedBy[i];
	}
	temp[noOfLikes - 1] = &liker;
	for (int i = 0; i < (noOfLikes - 1); i++) {
		delete LikedBy[i];
	}
	delete[] LikedBy;
	LikedBy = temp;
}
/*done part of 2 */ int Post::getPostDay() {
	return this->dateOfPost.getDay();
}
/*done part of 2 */ void Post::displayPostOnly() {
	cout << "Post Id: " << postId;
}
//Class Page functions
Page::Page() {
	postsnum = 0;
	pageId = 0;
	owner = nullptr;
	title = "";
	pagePosts = nullptr;
	noOfLikes = 0;
}
Page::Page(const Page& obj) {
	if (&obj == nullptr) {
		pageId = 0;
		owner = nullptr;
		title = "";
		postsnum = 0;
		pagePosts = nullptr;
		noOfLikes = 0;
		return;
	}
	if (this != &obj) {
		this->pageId = obj.pageId;
		this->owner = new User(*(obj.owner));
		this->title = obj.title;
		this->pagePosts = obj.pagePosts;	//ambigous
		this->noOfLikes = obj.noOfLikes;
		this->postsnum = obj.postsnum;
		this->pagePosts = new Post * [postsnum];
		for (int i = 0; i < postsnum; i++) {
			this->pagePosts[i] = new Post(*(obj.pagePosts[i]));
		}
	}
}
Page::~Page() {
	delete owner;
	for (int i = 0; i < postsnum; i++) {
		delete pagePosts[i];
	}
	delete[] pagePosts;
}
/*done 10 */void Page::veiwPage() {
	for (int i = 0; i < this->postsnum; i++) {
		cout << "Post " << i + 1 << ": " << pagePosts[i]->getId();
	}
}
string Page::getPagetitle() {return title;}
int Page::getpageId() {return pageId;}
User Page::getPageowner() { return *owner; }
int Page::getnoOfLikes() {return noOfLikes;}
int Page::getpostsnum() {return postsnum;}
Post* Page::getpagePosts(int x) {return pagePosts[x];}
void Page::setpageId(int x) { this->pageId=x; }
void Page::setpageOwner(int o) {
	owner=SocialNetworkApp::findUserById(o);
}
void Page::setpagetitle(string x) { title = x;}
void Page::setpagepostnum(int x) {postsnum = x;}
void Page::setnoOflikes(int x) {noOfLikes = x;}
void Page::createPagepostlist(int x){
		this->pagePosts = new Post*[x];
}
Post* Page::createPagepost(int x){
	this->pagePosts[x] = new Post ();
	return 	pagePosts[x];
}
	
	//Class activity functions
Activity::Activity():type(-1),value("") {}
Activity::Activity(int typ):type(typ){
	setActivity(type);
}
Activity::Activity(const Activity& obj) {
	this->type = obj.type;
	this->value = obj.value;
}
void Activity::displayActivity() {
	cout << "\nShowing Activity\n" ;
	switch (this->type) {
	case 1:
		cout << "\nFeeling " << value << endl;
		break;
	case 2:
		cout << "\nThinking about " << value << endl;
		break;
	case 3:
		cout << "\nMaking " << value << endl;
		break;
	case 4:
		cout << "\nCelebrating " << value << endl;
		break;
	default:
		break;
	}
}
void Activity::setActivity(int a) {
	if (a < 1 || a>4) {
		do {
			cout << "\nInvalid Activity Type. Re-enter it: ";
			cin >> a;
			cin.ignore();
		} while (a < 1 || a>4);
	}
	this->type = a;
	switch (this->type) {
	case 1:
		cout << "\nEnter a feeling: ";
		break;
	case 2:
		cout << "\nEnter what you are thinking about: ";
		break;
	case 3:
		cout << "\nEnter what you are making: ";
		break;
	case 4:
		cout << "\nEnter what you are celebrating: ";
		break;
	default:
		break;
	}
	getline(cin, this->value);
}
void Activity::setActivitytype(int x) { this->type = x; }
void Activity::setActivityvalue(string x) { this->value = x; }
int Activity::gettype() { return type; }
string Activity::getvalue() { return value; }

	//Class comment functions
Comment::Comment(string t = "", int id = 0) {
	text = t;
	commenterId = id;
	if (commenterId > 0)
		setCommenterByid(id);
	else
		commenter = nullptr;
}
Comment::~Comment() {
}
/*done 6*/void Comment::displayComment() {
	if (commenter != nullptr) { 
		cout << "Comment by " << commenter->getUsername() << ": " << text << endl;
	}
	else {
		cout << "Commenter not found!" << endl;
	}
}
string Comment::getcomtext() { return text; }
int Comment::getcommenterId() { return commenter->getuserId(); }
void Comment::setCommenterByid(int x) { commenter = SocialNetworkApp::findUserById(x); }
void Comment::setCommenter(User*& x) { commenter = x; }
void Comment::setComtext(string t) { this->text = t; }

class Memory: public Post{
	Post* originalPost;
public:
	Memory() { originalPost = nullptr; }
	Memory(Post* pos){
		originalPost = new Post(*pos);
	}
	void displayMemory(Post* mem) {
		if (originalPost) {
			originalPost->displayPostOnly();
		}
	}
	~Memory() {
		delete originalPost;
	}
};

//Social Network App Functions
SocialNetworkApp::SocialNetworkApp() {
	currentDate.setDate(0, 0, 0);
	currentUser = nullptr;
	pagesNum = 0;
	userNumber = 0;
	for (int i = 0; i < pagesNum; i++) {
		allPages[i] = nullptr;
	}
	for (int i = 0; i < userNumber; i++) {
		allUsers[i] = nullptr;
	}
}
SocialNetworkApp::~SocialNetworkApp() {
	
	delete[] allPages;
	delete[] allUsers;
	currentUser, allPages, allUsers = nullptr;
}
User* SocialNetworkApp::findUserById(int id) {
	if (!allUsers) return nullptr;
	for (int i = 0; i < userNumber; i++) {
		if (allUsers[i]->getuserId() == id) {
			return allUsers[i];
		}
	}
	cout << "User not found." << endl;
	return nullptr;
}
User* SocialNetworkApp::setCurrentUser(int tempId) {
	if (findUserById(tempId) != 0)
		currentUser = findUserById(tempId);
	return currentUser;
}
Post* SocialNetworkApp::findPostById(int id) {
	for (int i = 0; i < userNumber; i++) {
		for (int j = 0; j < allUsers[i]->getpostnum(); j++) {
			if (allUsers[i]->getUserposts(j)->getId() == id) {
				return allUsers[i]->getUserposts(j);
			}
		}
	}
	for (int i = 0; i < pagesNum; i++) {
		for (int j = 0; j < allPages[i]->getpostsnum(); j++) {
			if (allPages[i]->getpagePosts(j)->getId() == id) {
				return allPages[i]->getpagePosts(j);
			}
		}
	}
	cout << "Post not found." << endl;
	return nullptr;
}
Page* SocialNetworkApp::findPageById(int id) {
	for (int i = 0; i < pagesNum; i++) {
		if (allPages[i]->getpageId() == id) {
			return allPages[i];
		}
	}
}
void SocialNetworkApp::loadData(ifstream& readData) {
	int tempint=0; string tempstr;
	//page data
	
		readData >> pagesNum;
		Page** temppage = new Page * [pagesNum];
		for (int i = 0; i < pagesNum; i++) {
			temppage[i] = new Page();
			readData >> tempint;
			temppage[i]->setpageId(tempint);
			readData >> tempstr;
			temppage[i]->setpagetitle(tempstr);
			readData >> tempint;
			temppage[i]->setpageOwner(tempint);
			readData >> tempint;
			temppage[i]->setnoOflikes(tempint);
			readData >> tempint;
			temppage[i]->setpagepostnum(tempint);
			temppage[i]->createPagepostlist(temppage[i]->getpostsnum());
			for (int j = 0; j < temppage[i]->getpostsnum(); j++) {
				Post* temppost = temppage[i]->createPagepost(j);
				if(temppost){
					readData >> tempint;
					temppost->setpostId(tempint);
					readData >> tempint;
					temppost->getpostDate().setDay(tempint);
					readData >> tempint;
					temppost->getpostDate().setMonth(tempint);
					readData >> tempint;
					temppost->getpostDate().setYear(tempint);
					readData >> tempstr;
					temppost->setPostDes(tempstr);
					readData >> tempint;
					temppost->getPostActivity().setActivitytype(tempint);
					readData >> tempstr;
					temppost->getPostActivity().setActivityvalue(tempstr);
					readData >> tempint;
					temppost->setNoofLikes(tempint);
					readData >> tempint;
					temppost->setNoOfComments(tempint);
					temppost->createPostComments(temppost->getnoOfComments());

					for (int k = 0; k < temppost->getnoOfComments(); k++) {
						Comment* tempcom = temppost->getpostcomment(k);
						readData >> tempint;
						tempcom->setCommenterByid(tempint);
						readData >> tempstr;
						tempcom->setComtext(tempstr);
					}
				}
				else {
					cerr << "Null post pointer at page[" << i << "], post[" << j << "]" << endl;
				}
			}

		}
		allPages = temppage;
	
	//USER DATA
	
		readData >> userNumber;
		User** tempuser = new User * [userNumber];
		for (int i = 0; i < userNumber; i++) {
			tempuser[i] = new User();
			readData >> tempint;
			tempuser[i]->setUserId(tempint);
			readData >> tempstr;
			tempuser[i]->setusername(tempstr);
			readData >> tempint;
			tempuser[i]->setFriendNum(tempint);
			tempuser[i]->createfriendlist(tempuser[i]->getfriendnum());
			for (int j = 0; j < tempuser[i]->getfriendnum(); j++) {
				readData >> tempint;
				tempuser[i]->setFriendById(tempint);
			}
			readData >> tempint;
			tempuser[i]->setPostNum(tempint);
			tempuser[i]->createuserposts(tempuser[i]->getpostnum());
			for (int k = 0; k < tempuser[i]->getpostnum(); k++) {
				Post* temppost =  tempuser[i]->getUserposts(k); 
				readData >> tempint;
				temppost->setpostId(tempint);
				readData >> tempint;
				temppost->getpostDate().setDay(tempint);
				readData >> tempint;
				temppost->getpostDate().setMonth(tempint);
				readData >> tempint;
				temppost->getpostDate().setYear(tempint);
				readData >> tempstr;
				temppost->setPostDes(tempstr);
				readData >> tempint;
				temppost->getPostActivity().setActivitytype(tempint);
				readData >> tempstr;
				temppost->getPostActivity().setActivityvalue(tempstr);
				readData >> tempint;
				temppost->setNoofLikes(tempint);
				readData >> tempint;
				temppost->setNoOfComments(tempint);
				temppost->createPostComments(temppost->getnoOfComments());

				for (int y = 0; y < temppost->getnoOfComments(); y++) {
					Comment* tempcom = temppost->getpostcomment(y); 
					readData >> tempint;
					tempcom->setCommenterByid(tempint);
					readData >> tempstr;
					tempcom->setComtext(tempstr);
				}
			}
		}
		allUsers = tempuser;
	
}
void SocialNetworkApp::storeData(ofstream& writeData) {
	//page data
	writeData << pagesNum << endl;		
	for (int i = 0; i < pagesNum; i++) {
			Page* temppage = (allPages[i]);
			writeData << temppage->getpageId() << endl << temppage->getPagetitle() << endl << temppage->getPageowner().getuserId();
			writeData << temppage->getnoOfLikes() << endl << temppage->getpostsnum() << endl;
			for (int j = 0; j < temppage->getpostsnum(); j++) {
				Post* temppost = temppage->getpagePosts(j); 
				writeData << temppost->getId() << endl << temppost->getpostDate().getDay() << endl;
				writeData << temppost->getpostDate().getMonth() << endl << temppost->getpostDate().getYear() << endl;
				writeData << temppost->getpostdes() << endl << temppost->getactivitytype() << endl;
				writeData << temppost->getactivityvalue() << endl << temppost->getnoOfLikes() << endl;
				writeData << temppost->getnoOfComments() << endl;
				for (int k = 0; k < temppost->getnoOfComments(); k++) {
					Comment* tempcom = temppost->getpostcomment(k);
					writeData << tempcom->getcommenterId() << endl << tempcom->getcomtext() << endl;
				}
			}
		}
	writeData << endl;
	//USER DATA
	writeData << userNumber << endl;
	for (int i = 0; i < userNumber; i++) {
		User* tempuser = (allUsers[i]);
		writeData << tempuser->getuserId() << endl << tempuser->getUsername() << endl;
		writeData << tempuser->getfriendnum() << endl;
		for (int j = 0; j < tempuser->getfriendnum(); j++) {
			writeData << tempuser->getuserfriend(j).getuserId() << endl;
		}
		writeData << tempuser->getpostnum() << endl;
		for (int k = 0; k < tempuser->getpostnum(); k++) {
			Post* temppost = tempuser->getUserposts(k);
			writeData << temppost->getId() << endl << temppost->getpostDate().getDay() << endl;
			writeData << temppost->getpostDate().getMonth() << endl << temppost->getpostDate().getYear() << endl;
			writeData << temppost->getpostdes() << endl << temppost->getactivitytype() << endl;
			writeData << temppost->getactivityvalue() << endl << temppost->getnoOfLikes() << endl;
			writeData << temppost->getnoOfComments() << endl;
			for (int y = 0; y < temppost->getnoOfComments(); y++) {
				Comment* tempcom = temppost->getpostcomment(y);
				writeData << tempcom->getcommenterId() << endl << tempcom->getcomtext() << endl;
			}
		}
	}
	
}

//raylib function
void inputId(char* id, int& idLength, bool &submitted) {
	if (!submitted) {
		
		DrawRectangle(650, 245, 200, 30, WHITE);
		if (!submitted) {
			int key = GetCharPressed();
			while (key) {
				if ((key >= '0') && (key <= '9') && (idLength < 15)) {
					id[idLength++] = (char)key;
					id[idLength] = '\0';
				}
				key = GetCharPressed(); 
			}

			if (IsKeyPressed(KEY_BACKSPACE) && idLength > 0) {
				id[--idLength] = '\0';
			}
			if (IsKeyPressed(KEY_ENTER)) {
				submitted = true;
			}
		}
		DrawText(id, 655, 247, 20, DARKBLUE);

	}
	
}
void inputcom(char* id4, int& idLength4, bool& submitted4) {
	if (!submitted4) {
		ClearBackground(WHITE);

		DrawRectangle(500, 200, 200, 150, WHITE);
		if (!submitted4) {
			int key = GetCharPressed();
			while (key) {
				if ((idLength4 < 100)) {
					id4[idLength4++] = (char)key;
					id4[idLength4] = '\0';
				}
				key = GetCharPressed();
			}

			if (IsKeyPressed(KEY_BACKSPACE) && idLength4 > 0) {
				id4[--idLength4] = '\0';
			}
			if (IsKeyPressed(KEY_ENTER)) {
				submitted4 = true;
			}
		}
		DrawText(id4, 505, 202, 15, DARKBLUE);

	}

}
Texture2D selectPics(int i) {
	if (i == 0) {
		DrawText("Ali's Post", 200, 200, 25, WHITE);
		return LoadTexture("image.JPG");
	}
	DrawText("Amna's Post", 600, 200, 25, WHITE);
	return LoadTexture("me.JPG");
}
void showlikedBy(int x) {
	if(x==0)
		DrawText("1. Amna", 190, 350, 25, WHITE);
	if(x==1)
		DrawText("2. Ayra", 190, 400, 25, WHITE);
	if(x==2)
		DrawText("3. Ali", 190, 450, 25, WHITE);

}
void showEndButton() {
	DrawRectangle(870, 290, 120, 40, BEIGE);
	DrawText("END", 880, 300, 20, RED);
}
void showSkipButton() {
	DrawRectangle(870, 290, 120, 40, BEIGE);
	DrawText("Skip Page", 880, 300, 20, DARKBLUE);
}
void showNextButton() {
	DrawRectangle(870, 290, 120, 40, BEIGE);
	DrawText("Next Page", 880, 300, 20, DARKBLUE);
	
}
void SocialNetworkApp::Run() {
	//read data
	ifstream readData("user.txt");
	if (readData.is_open()) {
		int a; string b;
		loadData(readData);
		readData >> a;
		readData.close();
	}
	//Date
	currentDate.setDay(15);
	currentDate.setMonth(5);
	currentDate.setYear(25);
			//start developing
	int selection = 0;
	const int screenWidth = 1000;
	const int screenLength = 600;
	InitWindow(screenWidth, screenLength, "Social Network App");
	SetTargetFPS(60);
	Texture2D Background = LoadTexture("background1.JPG");
	Rectangle sback= { 0,0,(float)Background.width,(float)Background.height };
	Rectangle dback = { 0 ,0,screenWidth,screenLength };
	Vector2 oback = { 0,0 };

	Rectangle box = { 870, 290, 120, 40 };
	char id[16]="";int idLength = 0,count=0;bool submitted = false;//0
	char id1[16] = "";int idLength1 = 0, count1 = 0;bool submitted1 = false;//2
	char id2[16] = ""; int idLength2 = 0; bool submitted2 = false;//3
	char id3[16] = "", id4[100] = "";int count3 = 0;int idLength3 = 0, idLength4 = 0; bool submitted3 = false, submitted4 = false;//4
	char id5[16] = ""; int idLength5 = 0; bool submitted5 = false;//5
	char id6[16] = "";int idLength6 = 0,count6=0;bool submitted6 = false;//6
	char id9[16] = "";int idLength9 = 0;bool submitted9 = 0;//9


	int temp;
	Texture2D imgname = LoadTexture("image.JPG");
	float x = 150, y = 250, desiredWidth = 200, desiredHeight = 200; temp = 2;
	Rectangle source = { 0,0,(float)imgname.width,(float)imgname.height };
	Rectangle dest = { x ,y,desiredWidth,desiredHeight };
	Vector2 origin = { 0,0 };
	Rectangle dest1 = { x+250 ,y,desiredWidth,desiredHeight };

	while (!WindowShouldClose()) {
		//0 entry page
		if(selection==0){
			BeginDrawing();
			DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
			DrawText("Welcome to ABEER'S app!", 190, 50, 50, WHITE);
			DrawText("Enter your ID and press ENTER:", 190, 250, 20, WHITE);
			inputId(id, idLength, submitted);
			if (submitted) {
				DrawText("ID submitted successfully!", 270, 300, 40, WHITE);
				count++;
			}
			EndDrawing();
			if (count == 40)
				selection = 1;
		}
		//1 home page
		if (selection == 1) {
			BeginDrawing();
			DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
			DrawText("Home Page", 190, 50, 50, WHITE);
			for (int i = 0; i < temp; i++) {
				Rectangle dest = { x + (i * 450),y,desiredWidth,desiredHeight };
				UnloadTexture(imgname);
				imgname = selectPics(i);
				DrawTexturePro(imgname, source, dest, origin, 0.0, WHITE);
			}
			showNextButton();
			Vector2 mousePos = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, box)) {
				selection=2;
			}
			EndDrawing();
		}
		//2 like a post
		if (selection == 2) {
			BeginDrawing();
			ClearBackground(WHITE);
			DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
			DrawText("Like Post", 190, 50, 50, WHITE);
			DrawText("Enter the Post ID you want to like:", 190, 250, 20, WHITE);
			inputId(id1, idLength1, submitted1);
			if (submitted1) {
				DrawText("Post liked successfully!", 270, 300, 40, WHITE);
				count1++;
			}
			showSkipButton();
			Vector2 mousePos = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, box)) {
				selection=3;
			}
			EndDrawing();
			if (count1 == 40)
				selection=3;
		}
		//3 view likers
		if (selection == 3) {
			BeginDrawing();
			DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
			DrawText("Post Likes", 190, 50, 50, WHITE);
			DrawText("Enter the Post ID :", 190, 250, 20, WHITE);
			inputId(id2, idLength2, submitted2);
			if (submitted2) {
				DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
				DrawText("Post Likes", 190, 50, 50, WHITE);
				DrawText("Liked By :", 190, 250, 35, WHITE);
				for (int i = 0; i < 3; i++) {
					showlikedBy(i);
				}
			}
			showNextButton();
			Vector2 mousePos = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, box)) {
				selection=4;
			}
			EndDrawing();
		}
		//4 add comment
		if (selection == 4) {
			BeginDrawing();
			DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
			DrawText("Add Comment", 190, 50, 50, WHITE);
			DrawText("Enter the Post ID", 190, 250, 20, WHITE);
			
			inputId(id3, idLength3, submitted3);
			if (submitted3) {
				DrawText("Enter the comment:", 190, 250, 20, WHITE);
				inputcom(id4, idLength4, submitted4);

			}
			if (submitted4) {
				DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
				DrawText("Comment Added!", 190, 250, 30, WHITE);
				count3++;

			}
			if (count3 == 40)
				selection=5;
			showSkipButton();
			Vector2 mousePos = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, box)) {
				selection=5;
			}
			EndDrawing();

		}
		//5 view post
		if (selection == 5) {
			BeginDrawing();
			DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
			DrawText("Veiw Post", 190, 50, 50, WHITE);
			DrawText("Enter Post ID :", 250, 250, 30, WHITE);
			inputId(id5, idLength5, submitted5);
			if (submitted5) {
				DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
				imgname = LoadTexture("1.JPG");
				DrawTexturePro(imgname, source, dest, origin, 0.0, WHITE);
				//show comments
				DrawText(id5, 270, 100, 50, WHITE);

			}

			showNextButton();
			Vector2 mousePos = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, box)) {
				selection=6;
			}
			EndDrawing();

		}
		//6 share memory
		if (selection == 6) {
			BeginDrawing();
			DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
			DrawText("Share Memory", 190, 50, 50, WHITE);
			DrawText("Enter the Post ID :", 190, 250, 20, WHITE);
			inputId(id6, idLength2, submitted2);
			if (submitted2) {
				DrawText("Post shared successfully!", 270, 300, 40, WHITE);
				count6++;
			}
			if (count6 == 40)
				selection = 7;
			showSkipButton();
			Vector2 mousePos = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, box)) {
				selection=7;
			}
			EndDrawing();
		}
		//7 profile
		if (selection == 7) {
			BeginDrawing();
			DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
			DrawText("Profile", 190, 50, 50, WHITE);
			DrawText("Username :		Maheen", 190, 210, 20, WHITE);
			DrawText("Posts :", 190, 270, 20, WHITE);
			imgname = LoadTexture("2.JPG");
			DrawTexturePro(imgname, source, dest1, origin, 0.0, WHITE);

			showNextButton();
			Vector2 mousePos = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, box)) {
				selection=8;
			}
			EndDrawing();
		}
		//8 friendlist
		if (selection == 8) {
			BeginDrawing();
			DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
			DrawText("My Friend List", 270, 100, 50, WHITE);
			DrawText("Ali Hassan", 270, 200, 25, WHITE);
			DrawText("Amna Shafiq", 270, 300, 25, WHITE);
			showNextButton();
			Vector2 mousePos = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, box)) {
				selection=9;
			}
			EndDrawing();
		}
		//9 view page
		if (selection == 9) {
			BeginDrawing();
			DrawTexturePro(Background, sback, dback, oback, 0.0, WHITE);
			DrawText("View Page", 270, 100, 50, WHITE);
			DrawText("Enter the Page ID :", 250, 250, 20, WHITE);
			inputId(id9, idLength9, submitted9);
			if (submitted9) {
				imgname = LoadTexture("me.JPG");
				DrawTexturePro(imgname, source, dest, origin, 0.0, WHITE);
			}
			showEndButton();
			Vector2 mousePos = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, box)) {
				selection = 10;
				break;
			}
			EndDrawing();			
		}

	}
	
	UnloadTexture(Background);
	UnloadTexture(imgname);
	CloseWindow();

	//store data
	ofstream writeData("user.txt");
	storeData(writeData);
	writeData.close();
}

int main() {
	SocialNetworkApp::Run();
}
