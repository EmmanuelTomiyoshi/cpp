#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
  public:
	void complain (std::string level);

  private:
	void debug (void);
	void info (void);
	void warning (void);
	void error (void);
	typedef struct {
		std::string name;
		void (Harl::*f)();
	} options_t;
};

#endif
