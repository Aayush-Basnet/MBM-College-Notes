// Sample cart data (you can replace this with your own cart data)
const cartItems = [
    { id: 1, name: "UtsavA_Book_24179", price: 200 },
    { id: 2, name: "UtsavA_Copy_24179", price: 100 },
    { id: 3, name: "UtsavA_Pen_24179", price: 25 }
];

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

// Function to empty the cart
function emptyCart() {
    cartItems.length = 0; // Clear the cartItems array
    displayCartItems(); // Update the cart display
}

// Initial display
displayCartItems();
