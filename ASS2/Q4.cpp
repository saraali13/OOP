#include <iostream>
using namespace std;

class Post;
class RegularUser;
class BusinessUser;

void passwordEncryption(string& password) 
{
	cout<<"Encrypted password\n";
    string key = "nothing";
    for (int i = 0; i < password.length(); i++) 
    {
        password[i] = password[i] ^ key[i % key.length()];
        cout<<password[i];
    }
    cout<<endl;
}

void passwordDecryption(string& password) 
{
    passwordEncryption(password); // Decryption is the same as encryption for XOR
}

//post class
class Post 
{
public:
    int postId;
    string content;
    int likes;
    string comments[100];
    int no_of_comments;
    int views;
//parameterized constructor
    Post(int postId, string content) : content(content), postId(postId), likes(0), no_of_comments(0), views(0)
     {}

//function for adding comments
    void addingComments(string comment) 
    {
        comments[no_of_comments] = comment;
        no_of_comments++;
    }

//function for adding likes
    void like() 
    {
        likes++;
    }

//function for adding views
    void view() 
    {
        views++;
    }

//setter functions
    void setLikes(int x)
    {
        likes*=x;
    }
    
     void setViews(int x)
    {
        views*=x;
    }

//function for displaying post's details
    void displaypostdetails() 
    {
        cout << "\nThe post id is = " << postId;
        cout << "\ncontent = " << content;
        cout << "\nlikes = " << likes;
        cout << "\nno of Comments = " << no_of_comments;
        cout << "\nviews = " << views<<endl;
    }
};

//user class:base class
class User 
{
public:
    string username;
    string email;
    string password;

    User(string username, string email, string password) : username(username), email(email), password(password) 
    {}

//function for verifying a user
    virtual bool verifyUser(string inputPassword) = 0;

//function for printing the user's verification
    void printVerificationMessage(bool verified) 
    {
        if (verified) 
		{

            cout << "User verified\n";
        }
    }
};

//regular user class: derived from user class
class RegularUser : public User 
{
public:
    int feedSize;
    static const int MAX_FEED_SIZE = 10;
    Post* feed[MAX_FEED_SIZE];

//parameterized constructor
    RegularUser(string username, string email, string password) : User(username, email, password), feedSize(0) 
    {}

//function for adding a post to feed
    void addToFeed(Post &fe) 
    {
        if (feedSize <= 5) 
        {
            feed[feedSize] = &fe;
            feedSize++;
        } else {
            cout << "reached post limit\n";
            return;
        }
    }
//function for viewing feed
    void viewFeed() 
    {
        for (int i = 0; i < feedSize; i++) 
        {
            feed[i]->displaypostdetails();
        }
    }
//function for verifying user
    bool verifyUser(string inputPassword) override 
    {
        string decryptedPassword = inputPassword;
        passwordDecryption(decryptedPassword);
        bool verified = decryptedPassword == password;
        printVerificationMessage(verified);
        return verified;
    }
};

//business user class: derived from user class
class BusinessUser : public User 
{
public:
    int promotionLimit = 10;
    static int countpromote;

//parameterized constructor
    BusinessUser(string username, string email, string password) : User(username, email, password) {}

//functions for promoting a post
    void promotePost(Post &post) 
    {
        if (checkPromotionLimit(post)) 
        {
            cout << "Post promoted successfully\n";
            post.setLikes(2);
            post.setViews(3);
        }
    }

    bool checkPromotionLimit(Post &post) 
    {
        if (countpromote > promotionLimit) 
        {
            cout << "Post promotion limit reached\n";
            return 0;
        }
        countpromote++;
        return 1;
    }

//function for user verification
    bool verifyUser(string inputPassword) override 
    {
        string decryptedPassword = inputPassword;
        passwordDecryption(decryptedPassword);
        bool verified = decryptedPassword == password;
        printVerificationMessage(verified);
        return verified;
    }
};

int BusinessUser::countpromote = 0;

int main() 
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
    RegularUser regularUser("u1", "user1@instagaram.com", "pass1xyz");
    BusinessUser businessUser("bu1", "business1@instagram.com", "pass2xyz");
    string pass1="pass1xyz";
    string pass2="pass2xyz";
    cout << "User1 verified: " << regularUser.verifyUser("pass1xyz") << endl;
    cout << "User2 verified: " << businessUser.verifyUser("pass2xyz") << endl;

    Post p1(191, "Hello people");
    Post p2(132, "Have a good day");
    Post p3(113, "Enjoyyyy");
    regularUser.addToFeed(p1);
    regularUser.addToFeed(p2);
    regularUser.addToFeed(p3);
    regularUser.viewFeed();
    p3.like();
    passwordEncryption(pass1);
    p3.addingComments("wow lovely post");
    businessUser.promotePost(p3);
    p2.displaypostdetails();
    p3.displaypostdetails();
    

    return 0;
}// end main
