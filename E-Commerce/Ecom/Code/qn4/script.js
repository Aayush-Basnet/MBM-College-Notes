// Sample product data (you can replace this with your own product data)
const products = [
    { id: 1, name: "UtsavA_Book_24179", price: 200 },
    { id: 2, name: "UtsavA_Copy_24179", price: 100 },
    { id: 3, name: "UtsavA_Pen_24179", price: 25 }
];

const cartItems = [];
const orderHistory = [];

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

// Function to perform checkout
function checkout() {
    if (cartItems.length === 0) {
        alert("cart is empty.");
        return;
    }

    const orderTotal = cartItems.reduce((total, item) => total + item.price, 0);
    const order = {
        items: [...cartItems],
        total: orderTotal
    };

    orderHistory.push(order);
    cartItems.length = 0; // Clear the cart
    displayCartItems();
    displayOrderHistory();
}

// Function to display order history
function displayOrderHistory() {
    const orderHistoryList = document.getElementById("orders");
    orderHistoryList.innerHTML = "";

    for (const order of orderHistory) {
        const li = document.createElement("li");
        li.classList.add("order-item");
        li.innerHTML = `<strong>Order Total: NRs.${order.total}</strong><br>Items: ${order.items.map(item => item.name).join(', ')}`;
        orderHistoryList.appendChild(li);
    }
}

// Initial display
displayProducts();
displayOrderHistory();
