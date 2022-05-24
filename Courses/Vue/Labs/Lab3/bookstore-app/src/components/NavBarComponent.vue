<template>
  <div class="sticky-top">
    <nav class="navbar navbar-expand-lg navbar-light app-navbar">
      <div class="container-fluid">
        <router-link to="/">
          <i class="fa fa-book"></i>
        </router-link>
        <button
          class="navbar-toggler"
          type="button"
          data-bs-toggle="collapse"
          data-bs-target="#navbarNav"
          aria-controls="navbarNav"
          aria-expanded="false"
          aria-label="Toggle navigation"
        >
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
          <ul class="navbar-nav">
            <li class="nav-item">
              <router-link class="nav-link" to="/">Books</router-link>
            </li>
            <li class="nav-item">
              <router-link class="nav-link" to="/wishlist">
                Wishlist
              </router-link>
            </li>
          </ul>
        </div>
      </div>
    </nav>
    <div v-if="store.wishlist.length" class="wishlist-note">
      <span>
        <router-link to="/wishlist" class="text-decoration-none">
          {{ store.wishlist.length }}
          <span>{{
            store.wishlist.length == 1 ? "book has" : "books have"
          }}</span>
          been added to your withlist
        </router-link>
      </span>
      <span @click="store.handleCheckout()" class="ms-2 btn-danger">
        Checkout
      </span>
    </div>
  </div>
</template>

<script>
import { store } from "../store.js";

export default {
  data: () => ({
    store,
  }),
};
</script>