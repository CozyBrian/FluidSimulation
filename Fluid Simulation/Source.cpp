#define OLC_PGE_APPLICATION
#include <olcPixelGameEngine.h>

using namespace std;

int N = 256;

struct FluidCube
{
	int size;
	float dt;
	float diff;
	float visc;

	float s[256 * 256];
	float density[256 * 256];

	float Vx[256 * 256];
	float Vy[256 * 256];

	float Ux[256 * 256];
	float Uy[256 * 256];

	void createFluid(float fdt, float fdiffusion, float fviscosity)
	{
		size = N;
		dt = dt;
		diff = fdiffusion;
		visc = fviscosity;
	}
};

class FluidSimulation : public olc::PixelGameEngine
{
public:
	FluidSimulation()
	{
		sAppName = "Render3D";
	}

private:
	FluidCube fluid;

	int IX(int x, int y)
	{
		return x + y * N;
	}

	void AddDensity(FluidCube &fluid, int x, int y, float amount)
	{
		int index = IX(x, y);
		fluid.density[index] += amount;
	}

	void AddVelocity(FluidCube &fluid, int x, int y, float amountX, float amountY)
	{
		int index = IX(x, y);
		fluid.Vy[index] += amountX;
		fluid.Vx[index] += amountY;
	}

public:
	bool OnUserCreate() override
	{
		fluid.createFluid(0.1, 0, 0);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);

		return true;
	}
};

int main()
{
	FluidSimulation game;
	if (game.Construct(256, 256, 2, 2))
	{
		game.Start();
	}
}