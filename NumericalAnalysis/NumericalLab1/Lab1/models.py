import math, numpy


class Root_Analysis:

    @staticmethod
    def get_analysis(numbers):
        nums = numpy.absolute(numbers)
        b = max(nums[1:])
        a = max(nums[:-1])
        r = Root_Analysis.calc_r(b, nums[0])
        R = Root_Analysis.calc_R(a, nums[len(nums)-1])
        return [r, R], [-R, -r]

    @staticmethod
    def calc_r(b, a0):
        return 1/(1 + b/math.fabs(a0))

    @staticmethod
    def calc_R(a, an):
        return 1 + a/math.fabs(an)

class Lobachevsky:
    #entry point
    @staticmethod
    def calculate(numbers, epsilon, n):
        steps, nums, p = Lobachevsky.make_steps(numbers, epsilon, n)
        roots = Lobachevsky.calc_roots(numbers, n, nums, p)
        return steps, roots

    @staticmethod
    def calc_quadr(numbers, n, k):
        ak = numbers[k]**2
        sum = 0
        j = 1
        while k-j >= 0 and k+j <= n:
            sum += (-1)**j * numbers[k - j] * numbers[k + j]
            j += 1
        return ak + 2 * sum

    @staticmethod
    def make_steps(numbers, epsilon, n):
        steps = []
        nums = list(numbers)
        k = 1
        iteration = 0
        while k > epsilon:
            iteration += 1
            numbersB = []
            part = []
            part.append(iteration)
            l = len(nums)
            for i in range(l):
                numbersB.append(Lobachevsky.calc_quadr(nums, n, i))
            part.append(numbersB)
            sum = 0
            l = len(numbersB)
            for i in range(l):
                sum += math.pow(1 - (numbersB[i]/(nums[i]**2)), 2)
            k = math.sqrt(sum)
            part.append(k)
            steps.append(part)
            nums = list(numbersB)
        return steps, nums, iteration

    @staticmethod
    def calc_roots(initials, n, numbers, p):
        func = Functions.equation
        xs = []
        p = 1/math.pow(2,p)
        for i in range(1, n+1, 1):
            xi = (numbers[n-i]/numbers[n-i+1])**float(p)
            xs.append(xi if math.fabs(func(initials, n, xi)) < math.fabs(func(initials, n, -xi)) else -xi)
        return xs


class Methods:

    #for equation
    @staticmethod
    def newtons_method(roots, epsilon, n, initials):
        answer = []
        ep = epsilon/10000
        for root in roots:
            x = root
            f, fd1 = Methods.calc_e_and_ed1(initials, n, x)
            while math.fabs(f/fd1) > ep:
                x = x - f/fd1
                f, fd1 = Methods.calc_e_and_ed1(initials, n, x)
            answer.append(x)
        return answer

    @staticmethod
    def calc_e_and_ed1(initials, n, x):
        return Functions.equation(initials, n, x), Functions.ed1(initials, n, x)

    #for function1
    @staticmethod
    def bisection_method(leftBorder, rightBorder, epsilon):
        func = Functions.function1
        Methods.checker(leftBorder, rightBorder, func, Functions.f1d1)
        a = leftBorder
        b = rightBorder
        steps = []
        iteration = 0
        while b-a > epsilon:
            iteration += 1
            c = (a + b)/2
            steps.append(Methods.create_step(iteration, a, b, c))
            if func(a) * func(c) < 0:
                b = c
            else:
                a = c
        x = (a+b)/2
        steps.append(Methods.create_step('answer', a, b, x))
        return steps, x


    #for function2
    @staticmethod
    def hybrid_method(leftBorder, rightBorder, epsilon):
        func = Functions.function2
        fd1 = Functions.f2d1
        fd2 = Functions.f2d2
        Methods.checker(leftBorder, rightBorder, func, fd1)
        xd = leftBorder
        xc = rightBorder
        steps = []
        iteration = 0
        try:
            if not func(xd) * fd2(xd) > 0: xd, xc = xc, xd
        except ZeroDivisionError as e:
            raise e
        while math.fabs(xd - xc) > epsilon:
            iteration += 1
            steps.append(Methods.create_step(iteration, xd, xc, (xd + xc) / 2))
            xd = Methods.newtons_iter(xd, func, fd1)
            xc = Methods.secant_iter(xc, xd, func)

        x = (xd+xc)/2
        steps.append(Methods.create_step('answer', xd, xc, x))
        return steps, x

    @staticmethod
    def newtons_iter(xd, f, fd1):
        return xd - f(xd)/fd1(xd)

    @staticmethod
    def secant_iter(xc, xd, f):
        return xc - (f(xc)*(xd - xc))/(f(xd) - f(xc))

    #for function2
    @staticmethod
    def fixed_point_iteration_method(leftBorder, rightBorder, epsilon):
        func = Functions.function2
        fd1 = Functions.f2d1
        try:
            Methods.checker(leftBorder, rightBorder, func, fd1)
        except Exception as e:
            raise e
        alpha = fd1(leftBorder)
        gamma = fd1(rightBorder)
        if alpha > gamma: alpha, gamma = gamma, alpha
        lam = 2/(alpha + gamma)
        q = math.fabs((gamma-alpha)/(alpha+gamma))
        newE = (1-q)/q * epsilon
        e = newE if newE < epsilon else epsilon
        xk = temp = leftBorder
        xk1 = rightBorder
        steps = []
        iteration = 0
        while math.fabs(xk1-xk) > e:
            iteration += 1
            steps.append(Methods.create_step(iteration, xk, xk1, (xk + xk1) / 2))
            xk = temp
            xk1 = xk - lam * func(xk)
            temp = xk1
        x = (xk + xk1) / 2
        steps.append(Methods.create_step('answer', xk, xk1, x))
        return steps, x

    @staticmethod
    def create_step(iteration, a, b, x):
        return iteration, x, a, b

    @staticmethod
    def checker(leftBorder, rightBorder, func, fd1):
        if leftBorder > rightBorder:
            leftBorder, rightBorder = rightBorder, leftBorder
        a = leftBorder
        b = rightBorder
        if func(a) * func(b) > 0:
            raise Exception("Function has no root on this interval")
        while a < b:
            if fd1(a) * fd1(b) < 0:
                raise Exception("Function is not monotone on this interval")
            a += 0.2


class Functions:

    @staticmethod
    def function1(x):
        return 1 + x**7 - math.log(1 + math.pi * math.cos(x**3)) + x**10 - (math.tan(x))**5 + x

    @staticmethod
    def f1d1(x):
        return 10*x**9 + 7*x**6 + (3 * math.pi * x**2 * math.sin(x**3))/(math.pi * math.cos(x**3) + 1) - (20 * (math.sin(2*x))**4 * (math.cos(x))**2)/((math.cos(2*x) + 1)**6) + 1

    @staticmethod
    def function2(x):
        return math.sqrt(math.fabs(x)) - 9 * x**2 + 23 - math.sin(x)

    @staticmethod
    def f2d1(x):
        try:
            return (x/(2 * (math.fabs(x))**(3/2))) - 18*x - math.cos(x)
        except ZeroDivisionError:
            raise ZeroDivisionError('Division by zero')

    @staticmethod
    def f2d2(x):
        try:
            return -((3 * x**2)/(4 * (math.fabs(x))**(7/2))) + (1/(2 * (math.fabs(x))**(3/2))) + math.sin(x) - 18
        except ZeroDivisionError:
            raise ZeroDivisionError('Division by zero')

    @staticmethod
    def equation(numbers, n, x):
        res = 0
        for i in range(n + 1):
            res += numbers[i] * math.pow(x, i)
        return res

    @staticmethod
    def ed1(numbers, n, x):
        res = 0
        for i in range(1, n + 1):
            res += numbers[i] * i * math.pow(x, i - 1)
        return res


class PlotBuilder:
    @staticmethod
    def build(f, left = -20, right=20, step = 0.0001):
        if left > right: left, right = right, left
        a = left
        b = right
        x = list()
        y = list()
        if f == '1': func = Functions.function1
        else: func = Functions.function2

        while a < b:
            x.append(a)
            y.append(func(a))
            a += step
        return x, y