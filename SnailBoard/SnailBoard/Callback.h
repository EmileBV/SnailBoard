#ifndef CALLBACK_H__
#define CALLBACK_H__

class Callback
{
public:
	Callback(void(*f)() = 0)
		: function(f){}
	void CallFunction() { function(); }

private:
	void(*function)();
};

#endif // !CALLBACK_H__
