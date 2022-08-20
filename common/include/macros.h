#pragma once

#define MEM_B(x) (*((byte *)(x)))

#define SIMPLE_FIELD(fileld_type, field_name)                                  \
public:                                                                        \
  void set_##field_name(fileld_type field_name) {                              \
    field_name##_ = field_name;                                                \
  }                                                                            \
  const fileld_type &field_name() { return field_name##_; }                    \
                                                                               \
private:                                                                       \
  fileld_type field_name##_
