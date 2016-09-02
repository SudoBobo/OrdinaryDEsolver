#include "RungeKuttaMethod.h"
#include "State.h"

RungeKuttaMethod::RungeKuttaMethod(Solver & solver, Limiter & limiter,
								   Conditions & conditions)
 : Method(solver, limiter, conditions)
{

}

void RungeKuttaMethod::calculateNext()
{
	m_solver.nextState() = m_solver.currentState() * 1.1;

	// ul(t+1) = ul(t) + (h / 6) * (k1 + ...)
	// наборы коэфициентов
	// изменяем текущий слой
	//???
//	int iSize = m_system.currentState.iSize()



	static const int iSize = m_solver.tempState().iSize();
	static const int jSize = m_solver.tempState().jSize();
	static const int kSize = m_solver.tempState().kSize();

	//
	// kTemp is needed, because while we do "k1 = limiter(k1)" we should not
	// change parts of k1
	//the idea is:
	// kTemp =  limiter(k1)
	// k1 = kTemp
	//
	static int orderOfMethod = 4;
	static State kTemp (iSize, jSize, kSize, m_conditions);
	static std::vector <State> K(orderOfMethod + 1, kTemp);

	static const int j = 0;
	static const double vDx = 666;
	static const double h = m_conditions.getH();
	//
	// system dU uses tempState in calculations
	// tempState is for argument for dU
	// see https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods
	// tempState is used in every step (of 4) in calculating r1/2/3/4 = f(temp)
	// расчёт k1
	//

	m_solver.tempState() = m_solver.currentState();

	static double step[4] = {0, h / 2.0, h / 2.0, h};

	for (int kN = 1; kN <= orderOfMethod; kN++)
	{
		m_solver.tempState().calculateValues();
		// Граничные условия в виде "закольцовывания"
		for (int k = 0; k < kSize; k++)
		{
			K[kN](0, j, k) = 1; //m_solver.dU(k, iSize - 1, 0, 1);
		}

		for (int k = 0; k < kSize; k++)
		{
			K[kN](iSize - 1, j, k) = 1; //m_solver.dU(k, iSize - 2, iSize - 1, 0);
		}

		// Расчёт всего, что "не на границе"
		// Можно объединить в одну for с двумя if

		for (int i = 1; i < iSize - 1; i++)
		{
			//...
			for (int k = 0; k < kSize; k++)
			{
				K[kN](i, j, k) = 1;// m_solver.dU(k, i - 1, i, i + 1);

			}

	}
		if (kN != 4)
		{
		m_solver.tempState() = m_solver.currentState() + K[kN] * step[kN];
		m_limiter.limit();
		}
		else
		{

		}
	}

	m_solver.nextState() = m_solver.currentState() +
						  (K[1] + K[2] * 2.0 + K[3] * 2.0 + K[4]) * (h/6.0);
}
