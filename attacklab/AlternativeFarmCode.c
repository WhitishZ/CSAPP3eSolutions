unsigned addval_273(unsigned x)
{
	__asm {
		mov rdi, rax
		ret
	}
}

unsigned addval_219(unsigned x)
{
	__asm {
		pop rax
		ret
	}
}

/* Add two arguments */
long add_xy(long x, long y)
{
	__asm {
		lea rax, [edi + rsi]
		ret
	}
}

unsigned getval_481()
{
	__asm {
		pop rsp
		mov edx, eax
		ret
	}
}

unsigned addval_190(unsigned x)
{
	__asm {
		mov rax, rsp
		ret
	}
}

unsigned addval_436(unsigned x)
{
	__asm {
		mov esi, ecx
		ret
	}
}

unsigned getval_159()
{
	__asm {
		mov ecx, edx
		ret
	}
}

unsigned addval_110(unsigned x)
{
	__asm {
		mov eax, esp
		ret
	}
}

unsigned addval_487(unsigned x)
{
	__asm {
		mov edx, eax
		ret
	}
}
