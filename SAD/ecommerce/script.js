// Array to store products
let products = [];


// DOM elements
const productList = document.getElementById('products');
const addProductForm = document.getElementById('addProductForm');
const productNameInput = document.getElementById('productName');
const categoryNameInput = document.getElementById('categoryName');
const productPriceInput = document.getElementById('productPrice');
const productDescriptionInput = document.getElementById('productDescription');
const searchProductForm = document.getElementById('searchProductForm');
const searchTermInput = document.getElementById('searchTerm');


// Function to add a product
function addProduct(event) {
    event.preventDefault();
    
    const name = productNameInput.value.trim();
    const category = categoryNameInput.value.trim();
    const price = parseFloat(productPriceInput.value);
    const description = productDescriptionInput.value.trim();
    
    if (name === '' || isNaN(price) || description === '') {
        alert('Please fill in all fields.');
        return;
    }
    
    const product = { name, category, price, description };
    products.push(product);
    
    // Clear form inputs
    productNameInput.value = '';
    categoryNameInput.value = '';
    productPriceInput.value = '';
    productDescriptionInput.value = '';


    displayProducts();
}


// Function to display all products
function displayProducts() {
    productList.innerHTML = '';
    products.forEach((product, index) => {
        const li = document.createElement('li');
        li.innerHTML = `<strong>${product.name}</strong> - $${product.price.toFixed(2)}<span style="float: right;">${product.category}</span><br>${product.description}`;
        productList.appendChild(li);
    });
}


// Function to search for products
function searchProducts(event) {
    event.preventDefault();
    
    const searchTerm = searchTermInput.value.trim().toLowerCase();
    if (searchTerm === '') {
        displayProducts();
        return;
    }
    
    const filteredProducts = products.filter(product => 
        product.name.toLowerCase().includes(searchTerm) ||
        product.description.toLowerCase().includes(searchTerm) ||
        product.category.toLowerCase().includes(searchTerm)
    );
    
    productList.innerHTML = '';
    if (filteredProducts.length > 0) {
        filteredProducts.forEach(product => {
            const li = document.createElement('li');
            li.innerHTML = `<strong>${product.name}</strong> - $${product.price.toFixed(2)}<span style="float: right;">${product.category}</span><br>${product.description}`;
            productList.appendChild(li);
        });
    } else {
        const li = document.createElement('li');
        li.textContent = 'No products found.';
        productList.appendChild(li);
    }
}


// Event listeners
addProductForm.addEventListener('submit', addProduct);
searchProductForm.addEventListener('submit', searchProducts);
