// Sample product data (you can replace this with your own product data)
const products = [
    { id: 1, name: "UtsavA_Book_24179", price: 200 },
    { id: 2, name: "UtsavA_Copy_24179", price: 100 },
    { id: 3, name: "UtsavA_Pen_24179", price: 25 }
];

const wishListItems = [];

// Function to display products
function displayProducts() {
    const productsList = document.getElementById("products");
    productsList.innerHTML = "";

    for (const product of products) {
        const li = document.createElement("li");
        li.innerHTML = `<strong>${product.name}</strong><br>Price: NRs.${product.price}<br><button onclick="addToWishList(${product.id})">Add to Wish List</button>`;
        productsList.appendChild(li);
    }
}

// Function to add a product to the wish list
function addToWishList(productId) {
    const product = products.find(p => p.id === productId);
    if (product) {
        wishListItems.push(product);
        displayWishListItems();
   }
}

// Function to display wish list items
function displayWishListItems() {
    const wishListItemsList = document.getElementById("wish-list-items");
    wishListItemsList.innerHTML = "";

    for (const item of wishListItems) {
        const li = document.createElement("li");
        li.innerHTML = `${item.name} - NRs.${item.price}`;
        wishListItemsList.appendChild(li);
    }
}

// Initial display
displayProducts();
