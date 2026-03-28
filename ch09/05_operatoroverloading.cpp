class SpreadsheetCell {
public:
  // Omitted for brevity
  SpreadsheetCell operator+(const SpreadsheetCell &cell) const;
  SpreadsheetCell &operator+=(const SpreadsheetCell &rhs);
  // Omitted for brevity
};

// examples
SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell &cell) const {
  return SpreadsheetCell(getValue() + cell.getValue());
}

SpreadsheetCell &SpreadsheetCell::operator+=(const SpreadsheetCell &rhs) {
  set(getValue() + rhs.getValue());
  return *this;
}

bool operator>=(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs) {
  return !(lhs < rhs);
}