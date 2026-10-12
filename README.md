slm - small language model

Usage: slm [-a alpha] k file length

Args:

- alpha: pseudocount
- k: kgram size
- file: input file
- length: output length

This is a primitive language model (artificial idiot).
It generates text based on kgram frequencies. That is,
how many times k sized sequences appear in text.

Summary on how it works:

Get distributions:

- kgrams: Move k sized window through it and update count for each individual window (kgram).
- next: Do the same with a k+1 sized window for distributions of letters following the kgrams.
- alphabet: Map letters occurring in text.

Generate text:

- Use Picker to choose a first k letters (w)
- Get distribution for each letter after w from next
- Let Picker choose next letter based on the distribution
- Set w to last k letters. Repeat

Picker:

- Create die from distribution
- Roll die
- Pick

Pseudocount:

- Alpha (number) is added to each letter in alphabet for distribution of next letter in Generate text
- If no letter followed w, we therefore get even distribution if alpha > 0
