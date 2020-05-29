// FILE: company.cpp
// CLASS implemented: company (see company.h for documentation)


#include <cassert>
#include "company.h"

//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif

namespace coen79_lab7
{
    company::company() {
        this->company_name = "";
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }
    //   Postcondition: The company object is initialized with empty company name

    company::company(const std::string& company_name) {
        assert(company_name.length() > 0);

        this->company_name = company_name;
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }
    //   Precondition: company_name is a non-empty string
    //   Postcondition: The company object is initialized with "company_name"

    company::company(const company &src) {
        Debug("Company copy constructor..." << std::endl);

        this->company_name = src.company_name;
        list_copy(src.head_ptr, this->head_ptr, this->tail_ptr);
    }


    company& company::operator= (const company &src) {
        Debug("Company assignemnt operator..." << std::endl);

        if(this == &src) {
          return *this;
        }
        this->company_name = src.company_name;
        list_copy(src.get_head(), this->head_ptr, this->tail_ptr);
        return *this;
    }


    company::~company() {
        list_clear(head_ptr);
    }


    std::string company::get_name() const {
        return company_name;
    }

    const node *company::get_head() const {
        return head_ptr;
    }

    const node *company::get_tail() const {
        return tail_ptr;
    }

    node* company::get_head() {
        return head_ptr;
    }

    node* company::get_tail() {
        return tail_ptr;
    }

    void company::print_items() {
        list_print(head_ptr);
    }


    bool company::insert(const std::string& product_name, const float& price) {

        assert(product_name.length() > 0);

        if (list_contains_item(head_ptr, product_name)) {
            return false;
        }

        if (head_ptr == NULL) {
            list_init(head_ptr, tail_ptr, product_name, price);
        }
        else {
            list_tail_insert(tail_ptr, product_name, price);
        }

        return true;
    }
    //      Precondition: product_name is a non-empty string
    //      Postcondition: Creates and inserts a new node (product) to the back of the linked list.
    //      Returns true if successfully inserted, and returns false if there is a duplicate

    bool company::erase(const std::string& product_name) {
        assert(product_name.length() > 0);
        node* cursor = list_search(head_ptr, product_name);
        if(cursor == NULL) {
          return false;
        }
        if(cursor == head_ptr) {
          list_head_remove(head_ptr);
        }
        node* precursor = head_ptr;
        while(precursor->getLink() != cursor) {
          precursor = precursor->getLink();
        }
        if(cursor == tail_ptr) {
          tail_ptr = precursor;
          precursor->setLink(NULL);
        } else {
          precursor->setLink(cursor->getLink());
        }
        delete cursor;
        return true;
    }
    //      Postcondition:  Erases the product that its name matches product_name. Returns true if the
    //      product has been found and deleted, returns false otherwise
}
