#include <iostream>
#include <string>
using namespace std;

// chain of responsiblity is the restrictions is to handle requests by passing them along a chain of handlers until one of the handlers processes it.

// User submits a complaint, and it is passed through a Support Chain:

// Customer Support
// Technical Support
// Manager

class ComplaintHandler
{
protected:
    ComplaintHandler *nextHandler;

public:
    ComplaintHandler() : nextHandler(nullptr) {}

    void setHandler(ComplaintHandler *handler)
    {
        nextHandler = handler;
    }

    virtual void handleReq(string issue)
    {
        if (nextHandler)
        {
            nextHandler->handleReq(issue);
        }
        else
        {
            cout << "Issue could not be resolved." << endl;
        }
    }

    virtual ~ComplaintHandler() {}
};

class CustomerSupport : public ComplaintHandler
{
public:
    void handleReq(string issue) override
    {
        if (issue == "General Inquiry")
        {
            cout << "Customer Support - " << issue << endl;
        }
        else
        {
            cout << "Passing the issue to the next level" << endl;
            ComplaintHandler::handleReq(issue);
        }
    }
};

class TechnicalSupport : public ComplaintHandler
{
public:
    void handleReq(string issue) override
    {
        if (issue == "Technical Problem")
        {
            cout << "Technical Support : " << issue << endl;
        }
        else
        {
            cout << "Passing the issue to the next level" << endl;
            ComplaintHandler::handleReq(issue);
        }
    }
};

class Manager : public ComplaintHandler
{
public:
    void handleReq(string issue) override
    {
        if (issue == "Escalated Complaint")
        {
            cout << "Manager: " << issue << endl;
        }
        else
        {
            cout << "Passing the issue to the next level" << endl;
            ComplaintHandler::handleReq(issue);
        }
    }
};

int main()
{

    CustomerSupport customerSupport;
    TechnicalSupport technicalSupport;
    Manager manager;

    customerSupport.setHandler(&technicalSupport);
    technicalSupport.setHandler(&manager);

    customerSupport.handleReq("General Inquiry");

    customerSupport.handleReq("Technical Problem");

    customerSupport.handleReq("Unknown Issue");

    return 0;
}
