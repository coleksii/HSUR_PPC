#ifndef FPS_HPP
#define FPS_HPP

# define SMOOTH 0.1
# include <time.h>

class Fps {
public:
	Fps();
	~Fps();
	void calcFps();
	bool counter(int *storage, int limit);
	double getCurrent() const;
	void setCurrent(double current);
	double getOld() const;
	void setOld(double old);
	double getDelta() const;
	void setDelta(double delta);
	void setFps(int fps);

	int getFps() const;

protected:
	double	current;
	double	old;
	double	delta;
	int		fps;
	void smooth_delta();
};


#endif
