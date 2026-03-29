#include <optional>
#include <string>
#include <string_view>

/*Abstract Class*/
class Cell {
public:
  virtual ~Cell() = default;
  virtual void setCell(std::string_view sv) = 0;
  virtual std::string getCell() const = 0;
};

class StringCell : public Cell {
public:
  virtual void setCell(std::string_view ssv) override;
  virtual std::string getCell() const override;

private:
  std::optional<std::string> mValue;
};

class FloatCell : public Cell {
public:
  virtual void setCell(float f);
  virtual void setCell(std::string_view fsv) override;
  virtual std::string getCell() const override;

private:
  static std::string floattoString(float value);
  static float stringtoFloat(std::string_view fsv);
  std::optional<float> mValue;
};

/*Not Implemented yet*/