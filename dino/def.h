#ifndef STATE
#define STATE

enum class State
{
	LANDING,
	MAIN,
	CHARACTER,
	GAME,
	SIZE
};

inline State& dec(State& state) {
	if (static_cast<int>(state) > 0)
		state = static_cast<State>(static_cast<int>(state) - 1);
	return state;
}

inline State& inc(State& state) {
	if ((int)state < static_cast<int>(State::SIZE) - 1)
		state = (State)((int)state + 1);
	return state;
}

#endif // !STATE