I'll solve both parts of this problem about Catalan numbers.

## (a) Find the generating function for the Catalan numbers

**Given recurrence:** $C_{n+1} = \sum_{i=0}^{n} (C_i \cdot C_{n-i})$ with $C_0 = 1$

**Step 1:** Set up the generating function
Let $C(x) = \sum_{n=0}^{\infty} C_n x^n$

**Step 2:** Use the convolution property
The sum $\sum_{i=0}^{n} C_i \cdot C_{n-i}$ is the coefficient of $x^n$ in $[C(x)]^2$

Therefore:
$$\sum_{n=0}^{\infty} C_{n+1} x^n = [C(x)]^2$$

**Step 3:** Rewrite the left side
$$\sum_{n=0}^{\infty} C_{n+1} x^n = \frac{1}{x}\sum_{n=0}^{\infty} C_{n+1} x^{n+1} = \frac{1}{x}\sum_{m=1}^{\infty} C_m x^m$$

$$= \frac{1}{x}(C(x) - C_0) = \frac{C(x) - 1}{x}$$

**Step 4:** Set up the equation
$$\frac{C(x) - 1}{x} = [C(x)]^2$$

$$C(x) - 1 = x[C(x)]^2$$

$$xC(x)^2 - C(x) + 1 = 0$$

**Step 5:** Solve using the quadratic formula
$$C(x) = \frac{1 \pm \sqrt{1 - 4x}}{2x}$$

**Step 6:** Choose the correct branch
We need $C(0) = C_0 = 1$. Using L'Hôpital's rule or series expansion, the "$-$" sign gives the correct limit:

$$\boxed{C(x) = \frac{1 - \sqrt{1-4x}}{2x}}$$

---

## (b) Show that $C_n = \frac{1}{n+1}\binom{2n}{n}$

**Given identity:** $\sqrt{1-x} = \sum_{n=0}^{\infty} \binom{1/2}{n}(-x)^n$

**Step 1:** Apply the identity with $x \to 4x$
$$\sqrt{1-4x} = \sum_{n=0}^{\infty} \binom{1/2}{n}(-4x)^n = \sum_{n=0}^{\infty} \binom{1/2}{n}(-1)^n 4^n x^n$$

**Step 2:** Substitute into $C(x)$
$$C(x) = \frac{1 - \sqrt{1-4x}}{2x} = \frac{1}{2x}\left(1 - \sum_{n=0}^{\infty} \binom{1/2}{n}(-4x)^n\right)$$

$$= \frac{1}{2x}\left(1 - 1 - \sum_{n=1}^{\infty} \binom{1/2}{n}(-4x)^n\right)$$

$$= \frac{1}{2x}\left(-\sum_{n=1}^{\infty} \binom{1/2}{n}(-4)^n x^n\right)$$

$$= -\frac{1}{2x}\sum_{n=1}^{\infty} \binom{1/2}{n}(-4)^n x^n$$

$$= -\frac{1}{2}\sum_{n=1}^{\infty} \binom{1/2}{n}(-4)^n x^{n-1}$$

**Step 3:** Reindex with $m = n-1$ (so $n = m+1$)
$$C(x) = -\frac{1}{2}\sum_{m=0}^{\infty} \binom{1/2}{m+1}(-4)^{m+1} x^m$$

$$= \frac{1}{2}\sum_{m=0}^{\infty} \binom{1/2}{m+1}(-1)^{m}4^{m+1} x^m$$

$$= 2\sum_{m=0}^{\infty} \binom{1/2}{m+1}(-1)^{m}4^{m} x^m$$

**Step 4:** Evaluate $\binom{1/2}{m+1}$
$$\binom{1/2}{m+1} = \frac{(1/2)(1/2-1)(1/2-2)\cdots(1/2-m)}{(m+1)!}$$

$$= \frac{(1/2)(-1/2)(-3/2)\cdots(-(2m-1)/2)}{(m+1)!}$$

$$= \frac{1 \cdot (-1) \cdot (-3) \cdots (-(2m-1))}{2^{m+1}(m+1)!}$$

$$= \frac{(-1)^m \cdot 1 \cdot 3 \cdot 5 \cdots (2m-1)}{2^{m+1}(m+1)!}$$

**Step 5:** Simplify using factorials
$$1 \cdot 3 \cdot 5 \cdots (2m-1) = \frac{(2m)!}{2^m \cdot m!}$$

Therefore:
$$\binom{1/2}{m+1} = \frac{(-1)^m(2m)!}{2^{m+1} \cdot 2^m \cdot m! \cdot (m+1)!} = \frac{(-1)^m(2m)!}{2^{2m+1} \cdot m! \cdot (m+1)!}$$

**Step 6:** Substitute back
$$C_m = 2 \cdot \binom{1/2}{m+1}(-1)^m 4^m = 2 \cdot \frac{(-1)^m(2m)!}{2^{2m+1}m!(m+1)!} \cdot (-1)^m \cdot 4^m$$

$$= \frac{(2m)!}{2^{2m} \cdot m!(m+1)!} \cdot 4^m = \frac{(2m)!}{m!(m+1)!}$$

$$= \frac{1}{m+1} \cdot \frac{(2m)!}{m! \cdot m!} = \boxed{\frac{1}{m+1}\binom{2m}{m}}$$

Therefore: $$C_n = \frac{1}{n+1}\binom{2n}{n}$$
