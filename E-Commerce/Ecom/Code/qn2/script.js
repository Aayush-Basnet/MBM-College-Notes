// Sample product data (you can replace this with your own product data)
const products = [
    { id: 1, name: "UtsavA_Book_24179", price: 200 },
    { id: 2, name: "UtsavA_Copy_24179", price: 100 },
    { id: 3, name: "UtsavA_Pen_24179", price: 25 }
];

const cartItems = [];

// Function to display products
function displayProducts() {
    const productsList = document.getElementById("products");
    productsList.innerHTML = "";

    for (const product of products) {
        const li = document.createElement("li");
        li.innerHTML = `<strong>${product.name}</strong><br>Price: NRs.${product.price}<br><button onclick="addToCart(${product.id})">Add to Cart</button>`;
        productsList.appendChild(li);
    }
}

// Function to add a product to the cart
function addToCart(productId) {
    const product = products.find(p => p.id === productId);
    if (product) {
        cartItems.push(product);
        displayCartItems();
    }
}

// Function to display cart items
function displayCartItems() {
    const cartItemsList = document.getElementById("cart-items");
    cartItemsList.innerHTML = "";

    for (const item of cartItems) {
        const li = document.createElement("li");
        li.innerHTML = `${item.name} - NRs.${item.price}`;
        cartItemsList.appendChild(li);
    }
}

// Function to handle the checkout (you can customize this)
function checkout() {
    alert("Checkout functionality not implemented in this example.");
}

// Initial display
displayProducts();
