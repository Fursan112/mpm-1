//! Insert a pointer
template <class T>
bool mpm::Handler<T>::insert(const std::shared_ptr<T>& ptr) {
  bool insertion_status =
      elements_.insert(std::make_pair(ptr->id(), ptr)).second;
  return insertion_status;
}

//! Insert a pointer at a given id
template <class T>
bool mpm::Handler<T>::insert(mpm::Index id, const std::shared_ptr<T>& ptr) {
  bool insertion_status = elements_.insert(std::make_pair(id, ptr)).second;
  return insertion_status;
}

//! Iterate over elements in the container
template <class T>
template <class Tunaryfn>
Tunaryfn mpm::Handler<T>::for_each(Tunaryfn fn) {
  for (const auto& element : elements_) {
    fn((element).second);
  }
  return fn;
}
