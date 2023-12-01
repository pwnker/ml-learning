
# Session 01 

```
1. Create and run tests
2. Gather data
2. Construct a mathematical model 
3. Tweak around the model to make it work better with the data and move closer to the desired result
4. This tweaked model is a neural network
```
---

## Artificial neurons
* **Artificial neurons** are the basic building blocks of any artificial neural network ~ `elementary units`
* An **artificial neuron** recieves one or more inputs and sums them to produce an output or so called `activation` 
* Usually each input has it's own separate `weight`
* And the sum is often added to a value know as `bias` ~ a value that is not dependent on the input and gives the final result of sum the needed offset before forwarding it into the activation function 
* Usually in the last step we put the sum through a *non-linear function* known as an activation function that produces the output
* Activation functions usually have a **sigmoid shape** but they may also take the form of other non-linear functions, *picewise linear functions* or *step-functions* 

---

## Finite difference
* With the idea of driving the `cost` of our model to 0 using derivatives let's explore a way of aproximating derivatives using a method named `finite difference`

* A thought about *finite diffrence method*: 
    * We should keep in mind that this method is not used in the realm of neural network engineering because it is **slow** and **inaccurate**
    * In contrast `finite difference` method can be used as the part of the our learning process when trying to understand how neural networks work
$$\$$
* *Let's recap*:  As of right now we are trying to find the `minimum` of the `cost function` by looking in which direction we want to move our parameter `w` so that we reach the `minimum` of our `cost function`

* From the definition of derivatives we know:
    $$L=\lim_{h \to 0}\frac{f(x + h) - f(x)}{h}$$ 
    *A function of a real variable f(x) is differentiable at a point a of its domain, if its domain contains an open interval I containing a, and the limit L exists This means that, for every positive real number $\epsilon$ (even very small), there exists a positive real number $\delta$ such that, for every h such that $|h|<\delta$ and $h \neq 0$ then $f(a+h)$ is defined, and*
    $$|L-\frac{f(a+h)-f(a)}{h}| < \epsilon$$
    Where `| ... |` denote the absolute value

* In other words we take the distance between the result of function `f` shifted by the parameter `h` and the the result of function `f` that is not shifted and we devide this distance by that same value `h`
* We do this as we drive the parameter `h` towords 0.
      
* From the definition of `finite difference` we know:
$$△_h[f](x)=f(x - h) - f(x)$$

* Let's combine both ideas to compute the error distance of our cost (`dw`) and the error distance of our bias (`db`)
    $$dw=\frac{(cost(w + eps, b) - cost(w, b))}{eps}$$
    $$db=\frac{(cost(w, b + eps) - cost(w, b))}{eps}$$

* Now let's adjust our parameters by subtracting `dw` from the parameter `w` and `db` from the parameter `b` 
    $$w = w - dw$$
    $$b = b - db$$

* The first issue we encounter when computing error distance values is that values appear to be a large numbers which results in our parameters `w`, `b` "jumping around too much" and never reaching the desired values

* Let's introduce the `learining rate` concept to our model 
    * We are now able to have more control over the learning speed of our model
    * In our case it will solve the issue of error distance values being large 
    $$w = w - (lear\_rate * dw)$$
    $$w = w - (lear\_rate * db)$$

---

## Activation function
* After an **arificial neuron** sums up all of it's weights and adds it's bias the ouput is forwards the sum through an **activation function** 
* The goal of the activation function is to take the summed up data, that can possably unbound or  "all over the place", and so to say isolate the value (exaple between 0 and 1) and make it non-linear.
* One of the standard activation functions is named `Sigmoid`

### Sigmoid
* *It's any mathematical function that hasi the characteristic "S"-shaped curve or sigmoid curve.* 
* In our case we will look at a sigmoid function that maps values from `-Infinity` to `+Infinity` to values from `0` to `1`
    * The closer you are to `-Infinity` the closer you are to `0`
    * The closer you are to `+Infinity` the closer you are to `1`
* Let's take a look at a common example of a sigmoid function ~ `Logistic function`
$$\sigma(x)=\frac{1}{1+e^{-x}}=\frac{e^{x}}{1+e^{x}}=1-\sigma(-x)$$

--- 