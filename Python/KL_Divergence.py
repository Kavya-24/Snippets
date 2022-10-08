from math import log2

def kl_divergence(p, q):
	kl_divergence = 0
	for i in range(min(len(p),len(q))):
		kl_divergence += p[i] * log2(p[i]/q[i])
	return kl_divergence

p = [0.5, 0.3, 0.1, 0.1]
q = [0.2, 0.3, 0.2, 0.3]

kld = kl_divergence(p, q)
print(kld)
