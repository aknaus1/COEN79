void sequence :: insert(const value_type& entry) {
  if(many_nodes == 0) { //Empty list
    list_head_insert(head_ptr, entry);
    cursor = head_ptr;
    precursor = NULL;
    tail_ptr = head_ptr;
  } else if(cursor == head_ptr) { //insert at head
    list_head_insert(head_ptr, entry);
    cursor = head_ptr;
    precursor = NULL;
  } else if(!is_item()) { //insert after tail
    list_insert(tail_ptr, entry);
    tail_ptr = tail_ptr->link();
    end();
  } else { //insert in middle
    list_insert(precursor, entry);
    cursor = precursor->link();
  }
  many_nodes++;
}
void sequence :: attach(const value_type& entry) {
  if(many_nodes == 0) { //Empty list
    list_head_insert(head_ptr, entry);
    cursor = head_ptr;
    precursor = NULL;
    tail_ptr = head_ptr;
  } else if(!is_item() || cursor == tail_ptr) { //attach to tail
    list_insert(tail_ptr, entry);
    tail_ptr = tail_ptr->link();
    end();
  } else { //attach in middle
    list_insert(cursor, entry);
    precursor = cursor;
    cursor = cursor->link();
  }
  many_nodes++;
}

void sequence :: remove_current() {
  assert(is_item());
  if(many_nodes == 1) {
    delete cursor;
    head_ptr = NULL;
    tail_ptr = NULL;
    precursor = NULL;
    cursor = NULL;
  } else if(cursor == head_ptr) {
    cursor = cursor->link();
    list_head_remove(head_ptr);
    precursor = NULL;
  } else if(cursor == tail_ptr) {
    delete cursor;
    tail_ptr = precursor;
    cursor = NULL;
    tail_ptr->set_link(NULL);
    end();
  } else {
    precursor->set_link(cursor->link());
    delete cursor;
    cursor = precursor->link();
  }
  many_nodes--;
}
